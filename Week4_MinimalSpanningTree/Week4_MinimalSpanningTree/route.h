#pragma once //replaces the "#ifndef #define #endif" truples. 

class route
{
public:
	double get_dist();
	bool ifconnect();
	void set_connect(bool x);
	void set_distance(double x);
	route(bool x=0, double y=999); //best practice is to put default argument in the declaration
	~route();

protected:

private:
	bool is_connect;
	double distance;

};
