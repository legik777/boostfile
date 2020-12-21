// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "../sources/boostf.cpp"
	std::vector<Broker> Broker::brokerVector;
TEST(file, searchtest) {
	std::string path_to_ftp = "../";
	std::vector<std::string> vec;
	vec = recdir(path_to_ftp);
	if (boost::filesystem::exists(path_to_ftp)) {
		std::cout << path_to_ftp << std::endl;
		EXPECT_EQ(422,  std::stoi(vec.back()));
		vec.pop_back();
	}
	else {
		std::cout << "dir not exist" << std::endl;
	}
  EXPECT_TRUE(true);
}
TEST(file, searchtest2) {
	Broker::clearVector();
	bool test=true;
	std::vector<std::string> vect = { 
"broker:bcs account:00122223 files:46 lastdate:20181016",
"broker:bcs account:00123456 files:44 lastdate:20181014",
"broker:bcs account:00123458 files:48 lastdate:20181018",
"broker:bcs account:00143456 files:46 lastdate:20181016",
"broker:ib account:00100001 files:48 lastdate:20181018",
"broker:ib account:00100002 files:48 lastdate:20181018",
"broker:ib account:00100003 files:47 lastdate:20181017",
"broker:otkritie account:03934520 files:48 lastdate:20181018",
"broker:otkritie account:03934523 files:47 lastdate:20181017"};
	std::string path_to_ftp = "../";
	if (boost::filesystem::exists(path_to_ftp)) {
		std::cout << path_to_ftp << std::endl;
		recdir(path_to_ftp);
		std::vector<Broker> vec = Broker::ListBrokersv();
		for (int i = 0; i < vect.size(); i++) {
			if (vect[i] != vec[i].toString()) {
				std::cout << vect[i] << std::endl << vec[i].toString() << std::endl << std::endl;
				test = false;
				break;
		}
		}
		EXPECT_EQ(test, 1);
	}
	else {
		std::cout << "dir not exist" << std::endl;
	}
	EXPECT_TRUE(true);
}
