//#pragma once
#include <gtest/gtest.h>
#include <iostream>
#include "characterFactory.h"
//#include "JOURNEY_ACROSS_THE_MNT.cpp"

//2 unit tests for every concrete class (Binarion, Dataweaver, Technomancer,Generator)

    
    
    TEST(BINARION,checkDefualtAC)
        {
            std::shared_ptr<Profession> binarionTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Theodore The Terrorizer");

            EXPECT_EQ(binarionTest->getAC(),7);
        }

    TEST(BINARION,checkModifiedAC)
        {
            std::shared_ptr<Profession> binarionTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Theodore The Terrorizer");

            binarionTest->changeAC(20);
            EXPECT_EQ(binarionTest->getAC(),12);
        }
        
    TEST(BINARION, bitTwistTest) //attacks enemy
        {
            std::shared_ptr<Profession> binarionTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Theodore The Terrorizer");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Billy");

            binarionTest->selectAction(1, testDummy, true);

            EXPECT_EQ(testDummy->getHP(), 0);
            EXPECT_TRUE(testDummy->isDefeated());
        }

    TEST(GENERATOR,checkDefualtAC)
        {
            std::shared_ptr<Profession> generatorTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSecType, CharacterFactory::GeneratorType, "Andrew The Antagonizer");

            EXPECT_EQ(generatorTest->getAC(),5);
        }

    TEST(GENERATOR,checkModifiedAC)
        {
            std::shared_ptr<Profession> generatorTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSecType, CharacterFactory::GeneratorType, "Andrew The Antagonizer");

            generatorTest->changeAC(20);
            EXPECT_EQ(generatorTest->getAC(),12);
        }

    TEST(GENERATOR,generateEnergyTest)
        {
            std::shared_ptr<Profession> generatorTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSecType, CharacterFactory::GeneratorType, "Andrew The Antagonizer");

            generatorTest->selectAction(1, generatorTest, true);

            EXPECT_EQ(generatorTest->getEnergy(), 5);
        }

    TEST(TECHNOMANCER,checkDefualtHP)
        {
            std::shared_ptr<Profession> technomancerTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CEngType, CharacterFactory::TechnomancerType, "Randy The Radiator");

            EXPECT_EQ(technomancerTest->getHP(),80);
        }

    TEST(TECHNOMANCER,checkModifiedHP)
        {
            std::shared_ptr<Profession> technomancerTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CEngType, CharacterFactory::TechnomancerType, "Randy The Radiator");

            technomancerTest->changeHP(-3);
            EXPECT_EQ(technomancerTest->getHP(),77);
        }

    TEST(TECHNOMANCER,ShockPunchTest)
        {
            std::shared_ptr<Profession> technomancerTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CEngType, CharacterFactory::TechnomancerType, "Randy The Radiator");

            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::GeneratorType, "Billy");

            technomancerTest->selectAction(1, testDummy, true);
            EXPECT_EQ(testDummy->getHP(), 2);
            EXPECT_FALSE(testDummy->isDefeated());
        }
    
    TEST(DATAWEAVER,checkDefualtHP)
        {
            std::shared_ptr<Profession> dataweaverTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::JSType, CharacterFactory::DataweaverType, "Miles The Maleficent");

            EXPECT_EQ(dataweaverTest->getHP(),50);

        }

    TEST(DATAWEAVER,checkModifiedHP)
        {
            std::shared_ptr<Profession> dataweaverTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::JSType, CharacterFactory::DataweaverType, "Miles The Maleficent");

            dataweaverTest->changeHP(-3);
            EXPECT_EQ(dataweaverTest->getHP(),47);
        }


    TEST(DATAWEAVER, quickAttackTest)
        {
            std::shared_ptr<Profession> dataweaverTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::JSType, CharacterFactory::DataweaverType, "Miles The Maleficent");

            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::TechnomancerType, "Billy");

            dataweaverTest->selectAction(1, testDummy, true);
            EXPECT_EQ(testDummy->getHP(),0);
            EXPECT_TRUE(testDummy->isDefeated());

        }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}