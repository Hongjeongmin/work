#include <iostream>
using namespace std;

class Neuron
{
	public:
		double w_;
		double b_;
		
		double input_; 
		double output_; // saved for back-prop
		
		Neuron();
		Neuron(const double& w_input,const double& b_input);
		double getAct(const double& x);
		double feedForward(const double& _input);
		double getActGrad(const double& x);
		void propBacward(const double& target);
};

Neuron::Neuron()
{
	w_=2.0;
	b_=1.0;
}
Neuron::Neuron(const double& w_input,const double& b_input)
{
	this->w_ = w_input;
	this->b_ = b_input;
}


double Neuron::getAct(const double& x) // 함수과정 
{
	return x;
}
double Neuron::feedForward(const double& _input) // 시그마와 함수 과정 
{
	input_ = _input;
	const double sigma = w_ * input_ +b_;
	
	output_ = getAct(sigma);
	return output_;
}
double Neuron::getActGrad(const double& x)//미 
{
	// linear or idenity activation fucntion
	return 1.0;	
}
void Neuron::propBacward(const double& target) 
{
	const double alpha = 0.1; // lerning rate
	const double grad = (output_ - target) * getActGrad(output_);
	w_ -= alpha * grad * input_; // last input_) came from d(wx+b)/dw =x
	b_ -= alpha * grad * 1.0; // last 1.0 came from d(wx+b)/db = 1
}

int main()
{
	Neuron My_neuron(2.0,1.0);
	for(int i=0;i<100;i++)
	{
		cout<<"Trainin "<<i<<endl;
		My_neuron.feedForward(1.0);
		My_neuron.propBacward(4.0);
		cout<<"w = "<<My_neuron.w_ << " b = "<<My_neuron.b_<<endl;
	}
	
	return 0;
}
