#include "myserver.h"
#include "ui_myserver.h"

MyServer::MyServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyServer)
{
    ui->setupUi(this);

    //No puede conectar hasta tener los campos correspondientes rellenos.
    ui->StartPushButton->setEnabled(false);
    //La IP del servidor siempre va a ser Localhost.
    ui->SAddressLineEdit->setEnabled(false);
}

MyServer::~MyServer()
{
    delete ui;
}

void MyServer::sendSignal()
{
    QStringList files_;
    QDirIterator it(ui->FolderLineEdit->text(),
                    QStringList() << "-",
                    QDir::Files,
                    QDirIterator::Subdirectories);

    while (it.hasNext()){
        files_.push_back(it.next());
    }

    destination_ = new SendDestination(ui->FolderLineEdit->text(),
                                       files_,
                                       QHostAddress(ui->DAddressLineEdit->text()),
                                       ui->DPortLineEdit->text().toInt());
    destination_->run();
}

void MyServer::on_FindPushButton_clicked()
{
    QString fileName_ = QFileDialog::getExistingDirectory(this, "Open", "/home", QFileDialog::ShowDirsOnly);
    if (fileName_ != "") {
        ui->FolderLineEdit->setText(fileName_);
        //Ahora ya podemos iniciar.
        ui->StartPushButton->setEnabled(true);
    }
    else {
        QMessageBox::critical(this, "Directory not exist", "Can not open this directory");
    }
}

void MyServer::on_StartPushButton_clicked()
{
    ui->StartPushButton->setEnabled(false);
    server_= new MyQTcpServer(QHostAddress(ui->SAddressLineEdit->text()),
                              ui->SPortLineEdit->text().toInt(),
                              ui->FolderLineEdit->text(),this);
    server_->start();

    //Los archivos transferidos podemos enviarlos al servidor o a otro destino
    connect(server_, SIGNAL(closeSignal()), this, SLOT(sendSignal()));
}
