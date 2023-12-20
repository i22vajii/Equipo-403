// Testing function comprobar fecha

#include "gtest/gtest.h"
#include "actividad.h"

TEST(Actividad,Comprobarfecha1){
  EXPECT_FALSE(ComprobarFecha("01/01/2022"));
}

TEST(Actividad,Comprobarfecha2){
  EXPECT_TRUE(ComprobarFecha("20/12/2023"));
}
TEST(Actividad,Comprobarfecha3){
  EXPECT_TRUE(ComprobarFecha("31/12/2023"));
}

int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}