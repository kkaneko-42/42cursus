#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

class HumanA
{
	HumanA( std::string &name, Weapon &weapon );

	public:
		void attack( void ) const;
	private:
		std::string name;
		Weapon weapon;
};

#endif //HUMAN_A_HPP
