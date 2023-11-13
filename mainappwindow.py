import typing
from PyQt5 import QtCore
from PyQt5.QtWidgets import QApplication,QMainWindow, QWidget

from coba import Ui_MainWindow
from pages_function.user import userpag
class appmain(QMainWindow):
    def __init__(self):
        super(appmain,self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)


        self.userk = self.ui.user
        self.menu_btns_dict = {
            self.userk : userpag,
        }

        self.show_home_window()

        self.userk.btn_clicked.connect(self.show_selected_window)

    def show_home_window(self):
        result = self.open_tab_flag(self.userk)
        self.set_btn_checked(self.userk)

        if result[0]:
            self.ui.tabpage.setCurrentIndex(result[1])
        else:
            tab_title = self.userk.text()
            curIndex = self.ui.tabpage.addTab(userpag(), tab_title)
            self.ui.tabpage.setCurrentIndex(curIndex)
            self.ui.tabpage.setVisible(True)

    def set_btn_checked(self,btn):
        for button in self.menu_btns_dict.keys():
            if button != btn:
                button.setChecked(False)
            else:
                button.setChecked(True)
    
    def show_selected_window(self):
        button = self.sender()
        result = self.open_tab_flag(button.text())
        self.set_btn_checked(button)

        if result[0]:
            self.ui.tabpage.setCurrentIndex(result[1])
        else:
            tab_title = button.text()
            curIndex = self.ui.tabpage.addTab(self.menu_btns_dict[button](),tab_title)
            self.ui.tabpage.setCurrentIndex(curIndex)
            self.ui.tabpage.setVisible(True)

    def open_tab_flag(self,btn_text):
        open_tab_count = self.ui.tabpage.count()

        for i in range (open_tab_count):
            tab_title = self.ui.tabpage.tabText(i)
            if tab_title == btn_text:
                return True,i 
            else:
                continue
        return False

if __name__ == '__main__':
    import sys
    app = QApplication(sys.argv)
    window = appmain()
    window.show()
    sys.exit(app.exec())