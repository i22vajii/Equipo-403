// Testing function preinscribir usuario

#include "gtest/gtest.h"
#include "usuario.h"

TEST(Usuario, PreinscribirUsuario1){
  Usuario u;
  u.CargarUsuario("",8,"hola","");
  Actividad a("CB1","","","",20.5,8);
  EXPECT_TRUE(u.PreinscribirUsuario(a));
}

TEST(Usuario, PreinscribirUsuario2){
  Usuario u;
  u.CargarUsuario("",8,"hola","");
  Actividad a("CB2","","","",20.5,8);
  EXPECT_TRUE(u.PreinscribirUsuario(a));
}
TEST(Usuario, PreinscribirUsuario3){
  Usuario u;
  u.CargarUsuario("",8,"hola","");
  Actividad a("CB1","","","",20.5,8);
  EXPECT_FALSE(u.PreinscribirUsuario(a));
}

int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
