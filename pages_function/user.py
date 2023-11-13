from PyQt5.QtWidgets import QWidget,QApplication

from pages.user_page import Ui_user_page

class userpag(QWidget):
    def __init__(self):
        super(userpag,self).__init__()
        self.ui = Ui_user_page()
        self.ui.setupUi(self)




