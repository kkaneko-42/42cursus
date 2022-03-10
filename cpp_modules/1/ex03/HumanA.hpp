#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

class HumanA
{
	HumanA( const std::string &name, Weapon &weapon);

	public:
		void attack( void );
	private:
		std::string name;
		Weapon &weapon;
};

#endif //HUMAN_A_HPP
