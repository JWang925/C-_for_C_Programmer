class route
{
public:
	double get_dist();
	bool ifconnect();
	void set_connect(bool x);
	void set_distance(double x);
	route(bool x, double y);
	~route();

protected:

private:
	bool is_connect;
	double distance;

};
