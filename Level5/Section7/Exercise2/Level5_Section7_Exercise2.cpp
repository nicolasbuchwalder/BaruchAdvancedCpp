// Level5_Section7_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>


// PART A)

// structs for tags
struct IpAddress {};
struct DomainName {};

// DNS type
using DNS = boost::bimap <
	boost::bimaps::unordered_set_of < boost::bimaps::tagged < boost::uuids::uuid, IpAddress >>,
	boost::bimaps::unordered_set_of < boost::bimaps::tagged < std::string, DomainName >>,
	boost::bimaps::list_of_relation
>;

// PART C)

// function to print dns data
void print(const DNS& dnsDatabase) {
	std::cout << "existing dns: " << std::endl;
	for (auto it{ dnsDatabase.begin() }; it != dnsDatabase.end(); ++it) {
		std::cout << "   - ip: " << it->get<IpAddress>() << ", domain: " << it->get<DomainName>() << std::endl;
	}
}

int main() {

	// PART B)

	DNS dnsDatabase;
	boost::uuids::string_generator gen;

	// creating elements
	dnsDatabase.push_back(DNS::value_type(
		boost::uuids::uuid(gen("{01234567-89ab-cdef-0123-456789abcdef}")),
		"www.google.com"));

	dnsDatabase.push_back(DNS::value_type(
		boost::uuids::uuid(gen("{10394837-89ab-cdef-0123-456789abcdef}")), 
		"www.facebook.com"));

	dnsDatabase.push_back(DNS::value_type(
		boost::uuids::uuid(gen("{21480483-89ab-cdef-0123-456789abcdef}")), 
		"www.youtube.com"));
	
	// searching domain from ip
	boost::uuids::uuid searchIp{gen("{01234567-89ab-cdef-0123-456789abcdef}")};
	auto  searchIpIt = dnsDatabase.by<IpAddress>().find(searchIp);
	if (searchIpIt != dnsDatabase.by<IpAddress>().end()) {
		std::cout << "ip address '" << searchIp << "' has domain name: '" 
			<< searchIpIt->get<DomainName>() << "'" << std::endl;
	}

	// searching ip from domain
	std::string searchDomain{ "www.facebook.com" };
	auto  searchDomainIt{ dnsDatabase.by<DomainName>().find(searchDomain) };
	if (searchDomainIt != dnsDatabase.by<DomainName>().end()) {
		std::cout << "domain name '" << searchDomain << "' has ip address: '"
			<< searchDomainIt->get<IpAddress>() << "'" << std::endl;
	}
	std::cout << std::endl;
	
	// PART C)
	print(dnsDatabase);


}