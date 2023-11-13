from PyQt5.QtWidgets import QMessageBox
from PyQt5 import QtCore, QtGui, QtWidgets
import sys,res_rc

from loading1 import Ui_Formloading
from main import process
class Ui_Form(object):
    def loadingk(self):
        self.window = QtWidgets.QMainWindow()
        self.ui = Ui_Formloading()
        self.ui.setupUi(self.window)
        self.window.show()

    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(658, 505)
        Form.setWindowFlags(QtCore.Qt.FramelessWindowHint)
        Form.setAttribute(QtCore.Qt.WA_TranslucentBackground)
        self.gridLayout = QtWidgets.QGridLayout(Form)
        self.gridLayout.setObjectName("gridLayout")
        self.frame = QtWidgets.QFrame(Form)
        self.frame.setStyleSheet("QPushButton#pushButton{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ced4da, stop:0.2 #adb5bd, stop:0.4 #6c757d, stop:0.6 #6c757d, stop:0.8 #adb5bd, stop:1 #ced4da);\n"
"    color:rgba(255,255,255,210);\n"
"    border-radius:10px;\n"
"}\n"
"\n"
"QPushButton#pushButton:hover{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ced4da, stop:0.1 #adb5bd, stop:0.2 #6c757d, stop:0.8 #6c757d, stop:0.9 #adb5bd, stop:1 #ced4da);\n"
"}\n"
"\n"
"QPushButton#pushButton:pressed{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ced4da, stop:0.1 #adb5bd, stop:0.2 #6c757d, stop:0.8 #6c757d, stop:0.9 #adb5bd, stop:1 #ced4da);\n"
"    padding-left:5px;\n"
"    padding-top:5px;\n"
"}\n"
"\n"
"QPushButton#pushButton_2,#pushButton_3,#pushButton_4,#pushButton_5,#pushButton_6{\n"
"    background-color: rgba(0,0,0,0);\n"
"}\n"
"\n"
"QPushButton#pushButton_2:hover,#pushButton_3:hover,#pushButton_4:hover,#pushButton_5:hover,#pushButton_6:hover{\n"
"    background-color: rgba(0,0,0,0);\n"
"}\n"
"\n"
"QPushButton#pushButton_2:pressed,#pushButton_3:pressed,#pushButton_4:pressed,#pushButton_5:pressed,#pushButton_6:pressed{\n"
"    background-color: rgba(0,0,0,0);\n"
"    padding-left:5px;\n"
"    padding-top:5px;\n"
"}\n"
"\n"
"QLabel#label_7{\n"
"    color: #119da4;\n"
"}\n"
"\n"
"QLabel#label_8{\n"
"    image: url(:/icon/Icon/arduino-svgrepo-com (1).svg);\n"
"}\n"
"\n"
"QPushButton#pushButton_7{\n"
"    background-color: rgba(0,0,0,0);\n"
"    color: #119da4;\n"
"}")
        self.frame.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.frame.setFrameShadow(QtWidgets.QFrame.Raised)
        self.frame.setObjectName("frame")
        self.label = QtWidgets.QLabel(self.frame)
        self.label.setGeometry(QtCore.QRect(20, 30, 360, 430))
        self.label.setStyleSheet("border-image: url(:/image/Image/line-tracker.jpg);\n"
"border-top-left-radius: 50px;")
        self.label.setText("")
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.frame)
        self.label_2.setGeometry(QtCore.QRect(20, 30, 361, 430))
        self.label_2.setStyleSheet("background-color:rgba(0,0,0,40);\n"
"border-top-left-radius: 50px;")
        self.label_2.setText("")
        self.label_2.setObjectName("label_2")
        self.label_4 = QtWidgets.QLabel(self.frame)
        self.label_4.setGeometry(QtCore.QRect(380, 80, 231, 40))
        font = QtGui.QFont()
        font.setFamily("BankGothic Lt BT")
        font.setPointSize(20)
        font.setBold(True)
        font.setWeight(75)
        self.label_4.setFont(font)
        self.label_4.setStyleSheet("color:rgba(0,0,0,200);")
        self.label_4.setAlignment(QtCore.Qt.AlignCenter)
        self.label_4.setObjectName("label_4")
        self.lineEdit = QtWidgets.QLineEdit(self.frame)
        self.lineEdit.setGeometry(QtCore.QRect(400, 150, 190, 40))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.lineEdit.setFont(font)
        self.lineEdit.setStyleSheet("background-color:rgba(0,0,0,0);\n"
"broder:none;\n"
"border-bottom: 2px solid rgba(46,82,101,200);\n"
"color:rgba(0,0,0,240);\n"
"padding-bottom:7px;\n"
"border-radius:0.01px;\n"
"")
        self.lineEdit.setObjectName("lineEdit")
        self.lineEdit_2 = QtWidgets.QLineEdit(self.frame)
        self.lineEdit_2.setGeometry(QtCore.QRect(400, 210, 190, 40))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.lineEdit_2.setFont(font)
        self.lineEdit_2.setStyleSheet("background-color:rgba(0,0,0,0);\n"
"broder:none;\n"
"border-bottom: 2px solid rgba(46,82,101,200);\n"
"color:rgba(0,0,0,240);\n"
"padding-bottom:7px;\n"
"border-radius:0.01px;")
        self.lineEdit_2.setEchoMode(QtWidgets.QLineEdit.Password)
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.pushButton = QtWidgets.QPushButton(self.frame)
        self.pushButton.setGeometry(QtCore.QRect(450, 290, 100, 40))
        font = QtGui.QFont()
        font.setFamily("BankGothic Lt BT")
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton.setFont(font)
        self.pushButton.setStyleSheet("")
        self.pushButton.setObjectName("pushButton")
        self.label_3 = QtWidgets.QLabel(self.frame)
        self.label_3.setGeometry(QtCore.QRect(360, 30, 251, 430))
        self.label_3.setStyleSheet("background-color:rgba(255,255,255,255);\n"
"border-bottom-right-radius:50px;")
        self.label_3.setText("")
        self.label_3.setObjectName("label_3")
        self.label_5 = QtWidgets.QLabel(self.frame)
        self.label_5.setGeometry(QtCore.QRect(390, 340, 211, 20))
        font = QtGui.QFont()
        font.setPointSize(8)
        self.label_5.setFont(font)
        self.label_5.setAlignment(QtCore.Qt.AlignCenter)
        self.label_5.setObjectName("label_5")
        self.frame_2 = QtWidgets.QFrame(self.frame)
        self.frame_2.setGeometry(QtCore.QRect(400, 383, 186, 44))
        self.frame_2.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.frame_2.setFrameShadow(QtWidgets.QFrame.Raised)
        self.frame_2.setObjectName("frame_2")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.frame_2)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.pushButton_5 = QtWidgets.QPushButton(self.frame_2)
        self.pushButton_5.setText("")
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(":/icon/Icon/facebook-round-svgrepo-com.svg"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_5.setIcon(icon)
        self.pushButton_5.setObjectName("pushButton_5")
        self.horizontalLayout.addWidget(self.pushButton_5)
        self.pushButton_2 = QtWidgets.QPushButton(self.frame_2)
        font = QtGui.QFont()
        font.setFamily("Segoe UI Variable Display")
        self.pushButton_2.setFont(font)
        self.pushButton_2.setText("")
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(":/icon/Icon/twitter-round-svgrepo-com.svg"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_2.setIcon(icon1)
        self.pushButton_2.setObjectName("pushButton_2")
        self.horizontalLayout.addWidget(self.pushButton_2)
        self.pushButton_6 = QtWidgets.QPushButton(self.frame_2)
        self.pushButton_6.setText("")
        icon2 = QtGui.QIcon()
        icon2.addPixmap(QtGui.QPixmap(":/icon/Icon/youtube-round-svgrepo-com.svg"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_6.setIcon(icon2)
        self.pushButton_6.setObjectName("pushButton_6")
        self.horizontalLayout.addWidget(self.pushButton_6)
        self.pushButton_3 = QtWidgets.QPushButton(self.frame_2)
        self.pushButton_3.setText("")
        icon3 = QtGui.QIcon()
        icon3.addPixmap(QtGui.QPixmap(":/icon/Icon/github-142-svgrepo-com.svg"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_3.setIcon(icon3)
        self.pushButton_3.setObjectName("pushButton_3")
        self.horizontalLayout.addWidget(self.pushButton_3)
        self.pushButton_4 = QtWidgets.QPushButton(self.frame_2)
        self.pushButton_4.setText("")
        icon4 = QtGui.QIcon()
        icon4.addPixmap(QtGui.QPixmap(":/icon/Icon/discord-svgrepo-com.svg"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_4.setIcon(icon4)
        self.pushButton_4.setFlat(False)
        self.pushButton_4.setObjectName("pushButton_4")
        self.horizontalLayout.addWidget(self.pushButton_4)
        self.label_6 = QtWidgets.QLabel(self.frame)
        self.label_6.setGeometry(QtCore.QRect(390, 440, 121, 16))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_6.setFont(font)
        self.label_6.setObjectName("label_6")
        self.label_7 = QtWidgets.QLabel(self.frame)
        self.label_7.setGeometry(QtCore.QRect(510, 440, 101, 16))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_7.setFont(font)
        self.label_7.setObjectName("label_7")
        self.label_8 = QtWidgets.QLabel(self.frame)
        self.label_8.setGeometry(QtCore.QRect(40, 50, 60, 60))
        self.label_8.setText("")
        self.label_8.setObjectName("label_8")
        self.pushButton_7 = QtWidgets.QPushButton(self.frame)
        self.pushButton_7.setGeometry(QtCore.QRect(460, 356, 75, 24))
        font = QtGui.QFont()
        font.setPointSize(8)
        font.setBold(True)
        font.setUnderline(False)
        font.setWeight(75)
        self.pushButton_7.setFont(font)
        self.pushButton_7.setObjectName("pushButton_7")
        self.label_9 = QtWidgets.QLabel(self.frame)
        self.label_9.setGeometry(QtCore.QRect(560, 440, 16, 16))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_9.setFont(font)
        self.label_9.setObjectName("label_9")
        self.label_3.raise_()
        self.label.raise_()
        self.label_2.raise_()
        self.label_4.raise_()
        self.lineEdit.raise_()
        self.lineEdit_2.raise_()
        self.pushButton.raise_()
        self.label_5.raise_()
        self.frame_2.raise_()
        self.label_6.raise_()
        self.label_7.raise_()
        self.label_8.raise_()
        self.pushButton_7.raise_()
        self.label_9.raise_()
        self.gridLayout.addWidget(self.frame, 0, 0, 1, 1)

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)
        def openloading():
            process(self,self.lineEdit.text(),self.lineEdit_2.text(),Form)

        self.pushButton.clicked.connect(openloading)
        
    
    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "Form"))
        self.label_4.setText(_translate("Form", "ArduTracer"))
        self.lineEdit.setPlaceholderText(_translate("Form", "Username"))
        self.lineEdit_2.setPlaceholderText(_translate("Form", "Password"))
        self.pushButton.setText(_translate("Form", "Login"))
        self.label_5.setText(_translate("Form", "Forgot your username or password ?"))
        self.label_6.setText(_translate("Form", "Copyright © 2023"))
        self.label_7.setText(_translate("Form", "Group 1"))
        self.pushButton_7.setText(_translate("Form", "Click here"))
        self.label_9.setText(_translate("Form", "."))
    
       
        
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    Form = QtWidgets.QWidget()
    ui = Ui_Form()
    ui.setupUi(Form)
    Form.show()
    sys.exit(app.exec_())
