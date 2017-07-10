#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    //El cliente puede enviar o recibir datos, si envía los envía siempre al servidor LocalHost.
    //ui->ConnectPushButton->setEnabled(false);
    ui->SendPushButton->setEnabled(false);
    ui->DestinatioAddressLineEdit->setEnabled(false);
}

Client::~Client()
{
    delete ui;
}

void Client::on_ConnectPushButton_clicked()
{
    destination_ = new SendDestination(filename_,
                                       files_,
                                       QHostAddress (ui->ServerAddressLineEdit->text()),
                                       ui->ServerPortLineEdit->text().toInt());
    destination_->run();
}

void Client::on_SendPushButton_clicked()
{
    ui->SendPushButton->setEnabled(false);
    server_ = new MyQTcpServer(QHostAddress(ui->DestinatioAddressLineEdit->text()),
                               ui->DestinationPortLineEdit->text().toInt(),
                               ui->DestinationFolderLineEdit->text(),
                               this);
    server_->start();
}

void Client::on_OriginFindPushButton_clicked()
{
    filename_ = QFileDialog::getExistingDirectory(this, "Open", "/home", QFileDialog::ShowDirsOnly);

    if (filename_ != "") {
        ui->OriginFolderLineEdit->setText(filename_);

        QDirIterator it(filename_, QStringList() << "-", QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext()){
            files_.push_back(it.next());
        }
        ui->ConnectPushButton->setEnabled(true);
    }
    else {
        qDebug() << "No se puede abrir la carpeta";
    }
}

void Client::on_DestinationFindPushButton_clicked()
{
    filenameD_ = QFileDialog::getExistingDirectory(this, "Open", "/home", QFileDialog::ShowDirsOnly);
    if (filenameD_ != "") {
        ui->DestinationFolderLineEdit->setText(filenameD_);
        ui->SendPushButton->setEnabled(true);
    }
    else {
        qDebug() << "No se puede abrir la carpeta";
    }
}
