#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
	Weapon( std::string type );

	public:
		const std::string &getType( void );
		void setType( std::string type );

	private:
		std::string type;
};

#endif //WEAPON_HPP
