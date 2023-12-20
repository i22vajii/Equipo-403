// Testing function MostrarInscritos

#include "gtest/gtest.h"
#include "director.h"

TEST(Director, MostrarInscritos1){
  Director d;
  Actividad a("CB1","","","",20.5,8);
  EXPECT_TRUE(d.MostrarInscritos(a));
}

TEST(Director, MostrarInscritosNoExiste){
  Director d;
  Actividad a("CB2","","","",20.5,8);
  EXPECT_FALSE(d.MostrarInscritos(a));
}

TEST(Director, MostrarInscritosVacio){
  Director d;
  Actividad a("CC1","","","",20.5,8);
  EXPECT_FALSE(d.MostrarInscritos(a));
}

TEST(Director, MostrarInscritos3){
  Director d;
  Actividad a("CH1","","","",20.5,8);
  EXPECT_TRUE(d.MostrarInscritos(a));
}


int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
