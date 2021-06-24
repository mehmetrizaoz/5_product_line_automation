#include "form_product.h"
#include "ui_form_product.h"
#include <QGridLayout>
#include <QDesktopWidget>
#include <QStyle>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QtSql>
#include <QSqlError>
#include <QSqlQuery>

Form_Product::Form_Product(QWidget *parent) : QDialog(parent), ui(new Ui::Form_Product){
    ui->setupUi(this);
    this->setWindowTitle("Product");
    myDB = database();
    window()->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,window()->size(),qApp->desktop()->availableGeometry()));
    setStyleSheet("background-color: rgb(224,243,176)");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(ui->label,0,0);
    layout->addWidget(ui->lineEdit,0,1);
    layout->addWidget(ui->label_2,1,0);
    layout->addWidget(ui->lineEdit_2,1,1);
    layout->addWidget(ui->label_3,2,0);
    layout->addWidget(ui->comboBox,2,1);
    layout->addWidget(ui->label_4,3,0);
    layout->addWidget(ui->lineEdit_4,3,1);
    layout->addWidget(ui->label_5,4,0);
    layout->addWidget(ui->lineEdit_5,4,1);
    layout->addWidget(ui->label_6,5,0);
    layout->addWidget(ui->lineEdit_6,5,1);
    layout->addWidget(ui->label_7,6,0);
    layout->addWidget(ui->lineEdit_7,6,1);
    layout->addWidget(ui->label_8,7,0);
    layout->addWidget(ui->lineEdit_8,7,1);
    layout->addWidget(ui->label_9,8,0);
    layout->addWidget(ui->lineEdit_9,8,1);
    layout->addWidget(ui->process_product_recor,9,0,1,0);
    this->setLayout(layout);
}

Form_Product::~Form_Product(){
    delete ui;
}

void Form_Product::fill_product_line_combo_box(){
    QSqlQuery qry = myDB.executeQuery("SELECT * FROM productlines");
    vector<int> cols{0};
    int row = 1;
    ui->comboBox->clear();
    for(int i=1; i<=qry.size(); i++){
        QString lne = myDB.getCells(qry, row, cols);
        ui->comboBox->addItem(lne);
    }
}

QString Form_Product::get_mode(int m){
    if(m == ADD) { return "Add"; }
    else if(m == UPDATE) { return "Update"; }
    else if(m == DELETE) { return "Delete"; }
    return "";
}

void Form_Product::clear_form(){
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");
    ui->comboBox->setCurrentIndex(0);
}

void Form_Product::keyPressEvent(QKeyEvent *event){
    if(mode == DELETE || mode == UPDATE){
        if (event->key() == Qt::Key_Up){ //next record
            if(qr.next() == NULL){
                qr.first();
                recordOnScreen = 1;
            }
            else { recordOnScreen++; }
            populate_window();
        }
        if (event->key() == Qt::Key_Down){ //previous record
            if(qr.previous() == NULL){
                qr.last();
                recordOnScreen = qr.size();
            }
            else { recordOnScreen--; }
            populate_window();
        }
    }
}

void Form_Product::populate_window(){
    ui->lineEdit->setText(qr.value(0).toString());
    ui->lineEdit_2->setText(qr.value(1).toString());
    ui->comboBox->setCurrentText(qr.value(2).toString());
    ui->lineEdit_4->setText(qr.value(3).toString());
    ui->lineEdit_5->setText(qr.value(4).toString());
    ui->lineEdit_6->setText(qr.value(5).toString());
    ui->lineEdit_7->setText(qr.value(6).toString());
    ui->lineEdit_8->setText(qr.value(7).toString());
    ui->lineEdit_9->setText(qr.value(8).toString());
}

void Form_Product::on_show(){
    ui->process_product_recor->setText(get_mode(mode));
    clear_form();
    fill_product_line_combo_box();

    if( mode == ADD ){
    }
    else if(mode == UPDATE || mode == DELETE){
        qr = myDB.executeQuery("select * from products");
        qr.next();
        populate_window();
    }
}

void Form_Product::refresh_query(){
    QThread::msleep(100);
    qr = myDB.executeQuery("select * from products");
    qr.next();
    for(int i = 0; i<recordOnScreen-1; i++){ qr.next(); }
    populate_window();
}

void Form_Product::on_process_product_recor_clicked(){
    QString queryString;
    if( mode == ADD ){
        queryString = "insert into `products`(`productCode`,`productName`,`productLine`,`productScale`, \
                `productVendor`,`productDescription`,`quantityInStock`,`buyPrice`,`MSRP`) values(";
        queryString.append("'" + ui->lineEdit->text()   + "',");
        queryString.append("'" + ui->lineEdit_2->text() + "',");
        queryString.append("'" + ui->comboBox->currentText() + "',");
        queryString.append("'" + ui->lineEdit_4->text() + "',");
        queryString.append("'" + ui->lineEdit_5->text() + "',");
        queryString.append("'" + ui->lineEdit_6->text() + "',");
        queryString.append("'" + ui->lineEdit_7->text() + "',");
        queryString.append("'" + ui->lineEdit_8->text() + "',");
        queryString.append("'" + ui->lineEdit_9->text() + "')");
        myDB.executeQuery(queryString);
        clear_form();
    }
    else if( mode == UPDATE ){
        queryString = "UPDATE products SET ";
        queryString.append("productName = '" + ui->lineEdit_2->text() + "', ");
        queryString.append("productLine = '" + ui->comboBox->currentText() + "', ");
        queryString.append("productScale = '" + ui->lineEdit_4->text() + "', ");
        queryString.append("productVendor = '" + ui->lineEdit_5->text() + "', ");
        queryString.append("productDescription = '" + ui->lineEdit_6->text() + "', ");
        queryString.append("quantityInStock = '" + ui->lineEdit_7->text() + "', ");
        queryString.append("buyPrice = '" + ui->lineEdit_8->text() + "', ");
        queryString.append("MSRP = '" + ui->lineEdit_9->text() + "' ");
        queryString.append("where productCode = '" + ui->lineEdit->text() + "'");        
        myDB.executeQuery(queryString);
        refresh_query();
    }
    else if( mode == DELETE ){
        myDB.executeQuery("DELETE FROM products WHERE productCode = '" + ui->lineEdit->text() + "'");
        recordOnScreen--;
        refresh_query();
    }
}
