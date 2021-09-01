#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct Element {
public:
	Element(char op, double val) {
		operation = op;
		value = val;
	}

	char operation;
	double value;
};

class Function {
public:

	Function() {
		
	}

	void AddPart(const char& op, double val) {
		Element el = Element(op, val);
		elements.push_back(el);
	}

	double Apply(double value) const {
		double result = value;
		for(int i = 0; i < elements.size(); i++) {
			result = execute(result, elements[i]);
		}
		return result;
	}

	void Invert() {
		reverse(elements.begin(), elements.end());
	}

private:
	double execute(double result, Element el) const {
		char op = el.operation;
		double val = el.value;
		if(op == '+') {
			return result + val;
		}
		else {
			return result - val;
		}
	}
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
  function.AddPart('-', image.freshness * params.a + params.b);
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
  cout << ComputeQualityByWeight(params, image, 46) << endl;
  return 0;
}