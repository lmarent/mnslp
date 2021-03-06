/// ----------------------------------------*- mode: C++; -*--
/// @file policy_filter_container.h
/// The policy_filter_container class.
/// ----------------------------------------------------------
/// $Id: policy_filter_container.h 2558 2015-01-16 15:15:00 amarentes $
/// $HeadURL: https://./include/policy_filter_container.h $
// ===========================================================
//                      
// Copyright (C) 2014-2015, all rights reserved by
// - System and Computing Engineering, Universidad de los Andes
//
// More information and contact:
// https://www.uniandes.edu.co/
//                      
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; version 2 of the License
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// ===========================================================
#ifndef MNSLP__POLICY_FILTER_CONTAINER_H
#define MNSLP__POLICY_FILTER_CONTAINER_H

#include <map>
#include <string>
#include <libxml/xmlreader.h>

#include "policy_field_mapping.h"

namespace mnslp {


/**
 * This class helps to maintain the configuration for filters to apply
 *
 */
class policy_filter_container {

  public:

	policy_filter_container();
		
	policy_filter_container(const policy_filter_container &rhs);
		
	~policy_filter_container();

	/**
	 * This function assumes that the pointer is at the beginning of a 
	 * policy filter. When the function ends the pointer can be
	 * at the beginning of the next object or at the end of the document.
	 */ 
	void read_from_xml(xmlTextReaderPtr node);
	
	void set_filter(std::string key, policy_field_mapping _filter);
	
	bool operator==(const policy_filter_container &rhs) const;
	
	bool operator!=(const policy_filter_container &rhs) const;
	 
	typedef std::map<std::string, policy_field_mapping>::const_iterator const_iterator;
	const_iterator begin() const throw() { return filters.begin(); }
	const_iterator end() const throw() { return filters.end(); }

	bool check_field_availability(std::string app, msg::mnslp_field &field) const;	
	
	std::string get_field_traslate( std::string app, msg::mnslp_field &field ) const;
    
  private:
	std::map<std::string, policy_field_mapping> filters;
	
};

} // namespace mnslp

#endif // MNSLP__POLICY_FILTER_CONTAINER_H
