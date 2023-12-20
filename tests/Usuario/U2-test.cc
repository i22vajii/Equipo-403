// Testing function cancelar usuario

#include "gtest/gtest.h"
#include "usuario.h"

TEST(Usuario, CancelarPreinscripcion1){
  Usuario u;
  u.CargarUsuario("",8,"hola","");
  Actividad a("CB1","","","",20.5,8);
  EXPECT_TRUE(u.CancelarPreinscripcion(a));
}

TEST(Usuario, CancelarPreinscripcion2){
  Usuario u;
  u.CargarUsuario("",8,"hola","");
  Actividad a("CB1","","","",20.5,8);
  EXPECT_FALSE(u.CancelarPreinscripcion(a));
}
TEST(Usuario, CancelarPreinscripcion3){
  Usuario u;
  u.CargarUsuario("",8,"hola","");
  Actividad a("CB2","","","",20.5,8);
  EXPECT_FALSE(u.CancelarPreinscripcion(a));
}

int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
