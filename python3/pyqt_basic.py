# coding: utf-8
#

import sys
from PyQt5.QtWidgets import QApplication, QWidget

class ExampleWidget(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.resize(640, 480)
        #self.move(300, 300)
        self.setWindowTitle('sample')
        self.show()

if __name__ == '__main__':

    app = QApplication(sys.argv)
    ew = ExampleWidget()    
    sys.exit(app.exec_()) 
