/*-------------------------------------------

   clear sky

  --------------------------------------------*/
void clearSky() {
  // This 8x8 array represents the LED matrix pixels.
  // A value of 1 means we’ll fade the pixel to white
  int logo[8][8] = {
    {1, 0, 2, 0, 0, 2, 0, 1},
    {0, 1, 0, 2, 2, 0, 1, 0},
    {2, 0, 3, 1, 1, 3, 0, 2},
    {0, 2, 1, 0, 0, 1, 2, 0},
    {0, 2, 1, 0, 0, 1, 2, 0},
    {2, 0, 3, 1, 1, 3, 0, 2},
    {0, 1, 0, 2, 2, 0, 1, 0},
    {1, 0, 2, 0, 0, 2, 0, 1},
  };

  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 1) {
        fadePixel(column, row, off, sun_1, 50, 0);
      }
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 2) {
        fadePixel(column, row, off, sun_2, 50, 0);
      }
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 3) {
        fadePixel(column, row, off, sun_3, 30, 0);
      }
    }
  }
  delay(1500);
}

/*-------------------------------------------

   few clouds

  --------------------------------------------*/
void fewClouds() {
  // This 8x8 array represents the LED matrix pixels.
  // A value of 1 means we’ll fade the pixel to white
  int logo[8][8] = {
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 3, 3, 3, 1, 2, 1, 1},
    {3, 0, 0, 4, 3, 1, 2, 0},
    {3, 0, 0, 0, 4, 3, 1, 0},
    {3, 0, 0, 0, 4, 3, 4, 0},
    {0, 3, 3, 3, 3, 4, 3, 4},
    {0, 0, 0, 0, 0, 0, 0, 0}
  };

  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 3) {
        fadePixel(column, row, off, cloud_1, 30, 0);
      }
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 1) {
        fadePixel(column, row, off, sun_1, 50, 0);
      }
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 4) {
        fadePixel(column, row, off, cloud_2, 30, 0);
      }
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 2) {
        fadePixel(column, row, off, sun_2, 50, 0);
      }
    }
  }
  delay(1500);
}

///*-------------------------------------------
//
//   scattered clouds
//
//  --------------------------------------------*/
//void scatteredClouds() {
//  // This 8x8 array represents the LED matrix pixels.
//  // A value of 1 means we’ll fade the pixel to white
//  int logo[8][8] = {
//    {0, 0, 0, 0, 0, 0, 0, 0},
//    {0, 0, 0, 0, 0, 3, 0, 3},
//    {0, 1, 1, 1, 0, 0, 3, 0},
//    {1, 0, 0, 2, 1, 0, 0, 3},
//    {1, 0, 0, 0, 2, 1, 0, 0},
//    {1, 2, 0, 0, 2, 1, 2, 0},
//    {0, 1, 1, 1, 1, 2, 1, 2},
//    {0, 0, 0, 0, 0, 0, 0, 0}
//  };
//
//  for (int row = 0; row < 8; row++) {
//    for (int column = 0; column < 8; column++) {
//      if (logo[row][column] == 1) {
//        fadePixel(column, row, off, cloud_1, 30, 0);
//      }
//    }
//  }
//  for (int row = 0; row < 8; row++) {
//    for (int column = 0; column < 8; column++) {
//      if (logo[row][column] == 2) {
//        fadePixel(column, row, off, cloud_2, 50, 0);
//      }
//    }
//  }
//  for (int row = 0; row < 8; row++) {
//    for (int column = 0; column < 8; column++) {
//      if (logo[row][column] == 3) {
//        fadePixel(column, row, off, cloud_4, 50, 0);
//      }
//    }
//  }
//  delay(1500);
//}

/*-------------------------------------------

   broken clouds

  --------------------------------------------*/
void brokenClouds() {
  // This 8x8 array represents the LED matrix pixels.
  // A value of 1 means we’ll fade the pixel to white
  int logo[8][8] = {
    {0, 0, 0, 0, 0, 2, 0, 0},
    {0, 0, 0, 2, 2, 0, 2, 0},
    {4, 0, 2, 0, 0, 0, 4, 2},
    {0, 1, 1, 1, 0, 0, 4, 2},
    {1, 0, 0, 3, 1, 2, 2, 4},
    {1, 0, 0, 0, 3, 1, 0, 0},
    {1, 3, 0, 0, 3, 1, 3, 0},
    {0, 1, 1, 1, 1, 3, 1, 3}
  };

  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 1) {
        fadePixel(column, row, off, cloud_1, 30, 0);
      }
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 2) {
        fadePixel(column, row, off, cloud_3, 50, 0);
      }
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 3) {
        fadePixel(column, row, off, cloud_2, 50, 0);
      }
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 4) {
        fadePixel(column, row, off, cloud_4, 50, 0);
      }
    }
  }
  delay(1500);
}

/*-------------------------------------------

   shower rain

  --------------------------------------------*/
void showerRain() {

  int logo[8][8] = {
    {0, 3, 0, 2, 0, 0, 1, 0},
    {1, 2, 0, 1, 2, 1, 0, 2},
    {0, 0, 1, 3, 0, 1, 0, 0},
    {3, 1, 0, 1, 3, 2, 0, 1},
    {0, 1, 1, 0, 1, 0, 1, 0},
    {1, 0, 0, 1, 0, 1, 2, 1},
    {2, 1, 1, 0, 3, 0, 1, 0},
    {0, 1, 0, 2, 2, 3, 0, 0}
  };

  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 1) {
        fadePixel(column, row, off, cloud_1, 30, 0);
      }
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 2) {
        fadePixel(column, row, off, cloud_3, 50, 0);
      }
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 3) {
        fadePixel(column, row, off, cloud_2, 50, 0);
      }
    }
  }
  delay(1500);
}

///*-------------------------------------------
//
//   rain
//
//  --------------------------------------------*/
//void rain() {
//
//  int logo[8][8] = {
//    {0, 0, 0, 2, 0, 0, 1, 0},
//    {0, 1, 0, 1, 2, 1, 0, 2},
//    {0, 0, 1, 0, 0, 1, 0, 0},
//    {0, 1, 0, 1, 0, 2, 0, 1},
//    {0, 0, 1, 0, 1, 0, 1, 0},
//    {1, 0, 0, 1, 0, 1, 2, 1},
//    {2, 1, 1, 0, 0, 0, 1, 0},
//    {0, 1, 0, 0, 1, 0, 0, 0}
//  };
//
//  for (int row = 0; row < 8; row++) {
//    for (int column = 0; column < 8; column++) {
//      if (logo[row][column] == 1) {
//        fadePixel(column, row, off, cloud_1, 30, 0);
//      }
//    }
//  }
//  for (int row = 0; row < 8; row++) {
//    for (int column = 0; column < 8; column++) {
//      if (logo[row][column] == 2) {
//        fadePixel(column, row, off, cloud_3, 50, 0);
//      }
//    }
//  }
//  delay(1500);
//}

/*-------------------------------------------

   thunderstorm

  --------------------------------------------*/
void thunderstorm() {

  int logo[8][8] = {
    {0, 1, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 2, 1, 0, 3, 0},
    {1, 0, 0, 0, 2, 4, 0, 0},
    {1, 2, 3, 0, 3, 3, 2, 0},
    {3, 3, 3, 1, 1, 3, 3, 2},
    {0, 3, 4, 0, 3, 4, 0, 3},
    {3, 0, 0, 3, 3, 0, 4, 0},
    {0, 4, 0, 0, 4, 0, 0, 0}
  };

  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 1) {
        fadePixel(column, row, off, cloud_1, 30, 0);
      }
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 2) {
        fadePixel(column, row, off, cloud_2, 50, 0);
      }
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 3) {
        fadePixel(column, row, off, sun_3, 30, 0);
      }
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      if (logo[row][column] == 4) {
        fadePixel(column, row, off, sun_1, 50, 0);
      }
    }
  }
  delay(1500);
}

/*-------------------------------------------

   snow

  --------------------------------------------*/
//void snow() {
//
//  int logo[8][8] = {
//    {0, 3, 0, 2, 0, 0, 1, 0},
//    {1, 4, 0, 1, 4, 1, 4, 2},
//    {4, 0, 1, 3, 0, 4, 0, 0},
//    {3, 1, 0, 1, 3, 2, 4, 1},
//    {0, 1, 4, 0, 1, 0, 1, 0},
//    {1, 4, 3, 4, 0, 4, 2, 4},
//    {2, 1, 4, 0, 3, 0, 4, 0},
//    {0, 1, 0, 2, 2, 4, 0, 4}
//  };
//
//  for (int row = 0; row < 8; row++) {
//    for (int column = 0; column < 8; column++) {
//      if (logo[row][column] == 4) {
//        fadePixel(column, row, off, snow_1, 30, 0);
//      }
//    }
//  }
//  for (int row = 0; row < 8; row++) {
//    for (int column = 0; column < 8; column++) {
//      if (logo[row][column] == 1) {
//        fadePixel(column, row, off, cloud_1, 30, 0);
//      }
//    }
//  }
//  for (int row = 0; row < 8; row++) {
//    for (int column = 0; column < 8; column++) {
//      if (logo[row][column] == 2) {
//        fadePixel(column, row, off, cloud_4, 50, 0);
//      }
//    }
//  }
//  for (int row = 0; row < 8; row++) {
//    for (int column = 0; column < 8; column++) {
//      if (logo[row][column] == 3) {
//        fadePixel(column, row, off, cloud_2, 50, 0);
//      }
//    }
//  }
//  delay(1500);
//}
//
///*-------------------------------------------
//
//   mist
//
//  --------------------------------------------*/
//void mist() {
//
//  int logo[8][8] = {
//    {1, 1, 1, 3, 1, 1, 3, 1},
//    {2, 0, 0, 2, 2, 2, 0, 0},
//    {0, 0, 0, 0, 0, 0, 0, 0},
//    {1, 1, 3, 1, 3, 1, 1, 1},
//    {0, 2, 2, 2, 0, 0, 2, 0},
//    {1, 1, 1, 1, 1, 1, 3, 1},
//    {0, 0, 0, 2, 2, 0, 0, 0},
//    {0, 2, 0, 0, 0, 0, 2, 2}
//  };
//
//  for (int row = 0; row < 8; row++) {
//    for (int column = 0; column < 8; column++) {
//      if (logo[row][column] == 1) {
//        fadePixel(column, row, off, cloud_4, 30, 0);
//      }
//    }
//  }
//  for (int row = 0; row < 8; row++) {
//    for (int column = 0; column < 8; column++) {
//      if (logo[row][column] == 2) {
//        fadePixel(column, row, off, cloud_1, 30, 0);
//      }
//    }
//  }
//  for (int row = 0; row < 8; row++) {
//    for (int column = 0; column < 8; column++) {
//      if (logo[row][column] == 3) {
//        fadePixel(column, row, off, cloud_2, 30, 0);
//      }
//    }
//  }
//
//  delay(1500);
//}

