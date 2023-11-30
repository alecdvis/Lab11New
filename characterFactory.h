#pragma once

#include "Major.h"
#include "Profession.h"
#include <map>

class CharacterFactory {//creates a shared pointer to a profession (that contains the major)
    public:
        CharacterFactory(const CharacterFactory &) = delete;
        CharacterFactory & operator = (const CharacterFactory &) = delete;

        enum enumOfMajorType {CEngType, CSType, CSecType, JSType, OLEKAS_majorType, NoMajor};
        enum enumOfProfessionType {BinarionType, TechnomancerType, GeneratorType, DataweaverType, OLEKAS_professionType, NoProfession};

        std::shared_ptr<Profession> CreateCharacter(enumOfMajorType majorType, enumOfProfessionType ProfessionType, std::string name);

        static CharacterFactory& GetCharacterFactory();
    private:
        std::map<enumOfMajorType, std::shared_ptr<Major>> m_characterMap;

        CharacterFactory();
        ~CharacterFactory();
};