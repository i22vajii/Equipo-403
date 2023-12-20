// Testing function EnviarMail

#include "gtest/gtest.h"
#include "director.h"

TEST(Director, EnviarMail){
    Director d;
    EXPECT_TRUE(d.EnviarMail("Facultad de ciencias"));
}

TEST(Director, EnviarMailNoExiste){
    Director d;
    EXPECT_FALSE(d.EnviarMail("Noexiste"));
}

TEST(Director, EnviarMailDirectores){
    Director d;
    EXPECT_FALSE(d.EnviarMail("EPSC"));
}


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}