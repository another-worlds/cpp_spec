#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Element {
public:
	Element(char op, double val) {
		operation = op;
		value = val;
	}
	double Apply(const double& source_value) const {
		if (operation == '+') {
			return source_value + value;
		} else if (operation == '-') {
			return source_value - value;
		} else if (operation == '*') {  
			return source_value * value;
		} else if (operation == '/') {  
			return source_value / value;
		}
	}
	void Invert() {
		if (operation == '+') { 
			operation = '-'; 
		} else if (operation == '-') { 
			operation = '+'; 
		} else if (operation == '*') {
			operation = '/';
		} else if (operation == '/') {
			operation = '*';
		}
	}

private:
	char operation;
	double value;
};

class Function {
public:

	void AddPart(const char& op, double val) {
		Element el = Element(op, val);
		elements.push_back(el);
	}

	double Apply(double value) const {
		double result = value;
		for(const Element& el: elements) { result = el.Apply(result); }
		return result;
	}
 
	void Invert() {
		for(auto& el: elements) {
			el.Invert();
		}
		reverse(elements.begin(), elements.end());
	}

private:
	vector<Element> elements;
};

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}

