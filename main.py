def process(self, lineEdit, lineEdit_2, Form):
    if lineEdit == "user" and lineEdit_2 == "123":      
        self.loadingk()
        Form.close()

def processload(self,counter,Form):
    self.progressBar.setValue(counter)
    if counter>100:
        self.mainwi()
        Form.close()
    


        