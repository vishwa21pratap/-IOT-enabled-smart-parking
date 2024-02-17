import processing.serial.*;

Serial myPort;
String data = "";
PFont myFont;

void setup() {
  size(1366, 900);
  background(0);
  myPort = new Serial(this, "COM3", 9600);
  myPort.bufferUntil('\n');

  textAlign(CENTER);
  textSize(100);
  fill(#485DCE);
}

void draw() {
  background(0);
  displayMessage();
}

void serialEvent(Serial myPort) {
  data = myPort.readStringUntil('\n');
}

void displayMessage() {
  if (data != null && !data.equals("")) {
    String numericalPart = data.replaceAll("[^0-9]", "");
     
    if (!numericalPart.equals("")) {
      int distance = Integer.parseInt(numericalPart);

      fill(255);
      noFill();
      stroke(#4B5DCE);
      
      // Check distance and display appropriate message
      if (distance < 6) {
        showMessage("Stop");
      } else if (distance >= 6 && distance <= 15) {
        showMessage("Safe to park");
      }else{
        showMessage("free space");
      }
    }
  }
}

void showMessage(String message) {
  text(message, width / 2, height / 2);
}