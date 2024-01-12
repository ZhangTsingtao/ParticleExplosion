#ifndef PARTICLE_H_
#define PARTICLE_H_


namespace tz_SDL {

	struct Particle
	{
		double m_x;
		double m_y;

	private:
		double m_speed;
		double m_direction;

	private:
		void init();

	public:
		Particle();
		void update(int interval);

	};

}


#endif PARTICLE_H_


