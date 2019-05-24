#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

template <typename T>
class StatContainer : public std::vector<T>
{
public:
  T getMean()
  {
    T valueSum= 0;
    //instead of: for (typename std::vector<T>::const_iterator it = this->begin()...
    for (auto it = this->begin(); it!= this->end(); ++it)
      {
         valueSum += *it;
      }
    return valueSum / this->size();
  }
  T getVariance()
  {
    T sum=0., sum2=0.;
    for (auto it = this->begin(); it!= this->end(); ++it)
      {
        sum  += (*it);
        sum2 += (*it)*(*it);
      }
    return  sum2/this->size() - (sum/this->size()*sum/this->size());
  }
  T getMedian()
  {
    std::vector <T> tmpVector(*this);
    std::sort(tmpVector.begin(), tmpVector.end());
    return tmpVector.at(tmpVector.size()/2);
  }
  T getStd()
  {
    return sqrt(getVariance());
  }
  friend std::ostream& operator<< (std::ostream& stream, const StatContainer& statContainer)
  {
    for (auto it=statContainer.begin(); it!=statContainer.end(); ++it)
      {
         stream << "\t\t" << *it << std::endl;
      }
    return stream;
  }
};

int main()
{
        std::srand(1234);
	StatContainer<double> statContainer;
	for (size_t i=0; i< 20; i++)
	{
	  statContainer.push_back((double)rand()/RAND_MAX);
	}

	//typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	//boost::char_seperator<char> sep(",");
	//tokenizer tokens(float, sep);

	//" " << gsl_sf_erf(value / sqrt(2)) << StatContainer<double> statContainer;
	//for(tokenizer::iterator it = tokens.begin(); it != end.tokens; ++i){
		//statContainer.push_back
	//}
	std::cout << statContainer;
	std::cout << "    Mean: " << statContainer.getMean() << std::endl;
	std::cout << "     Std: " << statContainer.getStd() << std::endl;
	std::cout << "Variance: " << statContainer.getVariance() << std::endl;
	std::cout << "  Median: " << statContainer.getMedian() << std::endl;
	std::sort(statContainer.begin(),statContainer.end());
	std::cout << statContainer;
}
