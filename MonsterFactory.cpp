class Monster
{
    public:
        enum class HeightType
        {
            Short,
            Medium,
            Tall
        };
        enum class CreepyType
        {
            NotCreepy,
            Creepy,
            VeryCreepy
        };
    private:
        HeightType height;
        CreepyType creepiness;
    public:
        Monster(HeightType height, CreepyType creepiness)
            : height(height), creepiness(creepiness)
        {}
        HeightType GetHeight() const
        {
            return height;
        }
        CreepyType GetCreepiness() const
        {
            return creepiness;
        }
};

class MonsterFactory
{
    public:
        enum class MonsterType
        {
            Goblin,
            Orc,
            Slime            
        };
    public:
        Monster CreateMonster(MonsterType type)
        {
            switch(type)
            {
                case MonsterType::Goblin:
                    return Monster(Monster::HeightType::Short, Monster::CreepyType::NotCreepy);
                case MonsterType::Orc:
                    return Monster(Monster::HeightType::Tall, Monster::CreepyType::Creepy);
                case MonsterType::Slime:
                    return Monster(Monster::HeightType::Medium, Monster::CreepyType::VeryCreepy);
            }
        }
};

int main()
{
    MonsterFactory factory;
    
    Monster goblin = factory.CreateMonster(MonsterFactory::MonsterType::Goblin);
    Monster orc = factory.CreateMonster(MonsterFactory::MonsterType::Orc);
    Monster slime = factory.CreateMonster(MonsterFactory::MonsterType::Slime);
    
    return 0;
}