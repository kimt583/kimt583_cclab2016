// Crossfade entire screen from startColor to endColor
void fadeOut(int steps, int wait) {
  for(int i = 0; i <= steps; i++)
  {
     int newR = off_2.r + (off.r - off_2.r) * i / steps;
     int newG = off_2.g + (off.g - off_2.g) * i / steps;
     int newB = off_2.b + (off.b - off_2.b) * i / steps;
     
     matrix.fillScreen(matrix.Color(newR, newG, newB));
     matrix.show();
     delay(wait);
  }
}

// Fade pixel (x, y) from startColor to endColor
void fadePixel(int x, int y, RGB startColor, RGB endColor, int steps, int wait) {
  for (int i = 0; i <= steps; i++)
  {
    int newR = startColor.r + (endColor.r - startColor.r) * i / steps;
    int newG = startColor.g + (endColor.g - startColor.g) * i / steps;
    int newB = startColor.b + (endColor.b - startColor.b) * i / steps;

    matrix.drawPixel(x, y, matrix.Color(newR, newG, newB));
    matrix.show();
    delay(wait);
  }
}

void scrollText(String textToDisplay) {
  int x = matrix.width();
  
  // Account for 6 pixel wide characters plus a space
  int pixelsInText = textToDisplay.length() * 7;
  
  matrix.setCursor(x, 0);
  matrix.print(textToDisplay);
  matrix.show();
  
  while(x > (matrix.width() - pixelsInText)) {
    matrix.fillScreen(matrix.Color(off.r, off.g, off.b));
    matrix.setCursor(--x, 0);
    matrix.print(textToDisplay);
    matrix.show();
    delay(150);
  }
}

//void colorWipe(RGB color, uint8_t wait) {
//  for(uint16_t row=0; row < 8; row++) {
//    for(uint16_t column=0; column < 8; column++) {
//      matrix.drawPixel(column, row, matrix.Color(color.r, color.g, color.b));
//      matrix.show();
//      delay(wait);
//    }
//  }
//}


