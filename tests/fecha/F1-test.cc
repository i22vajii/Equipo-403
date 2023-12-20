// Testing function formato fecha

#include "gtest/gtest.h"
#include "actividad.h"

TEST(Actividad,FormatoFecha1){
  EXPECT_FALSE(FormatoFecha("31/02/20044"));
}

TEST(Actividad,FormatoFecha2){
  EXPECT_TRUE(FormatoFecha("01/01/2025"));
}
TEST(Actividad,FormatoFecha3){
  EXPECT_FALSE(FormatoFecha("00/00/2024"));
}

TEST(Actividad,FormatoFecha4){
  EXPECT_FALSE(FormatoFecha("10/-1/2024"));
}

int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}