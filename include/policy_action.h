/// ----------------------------------------*- mode: C++; -*--
/// @file policy_action_container.h
/// The policy_action_container class.
/// ----------------------------------------------------------
/// $Id: policy_action_container.h 2558 2015-01-16 15:15:00 amarentes $
/// $HeadURL: https://./include/policy_action_container.h $
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
#ifndef MNSLP__POLICY_ACTION_H
#define MNSLP__POLICY_ACTION_H

#include <map>
#include <string>
#include "mnslp_xml_node_reader.h"
#include "policy_action_mapping.h"

namespace mnslp {


/**
 * This class helps to maintain the mapping configuration for the export 
 * and action processes.
 *
 */
class policy_action : public mnslp_xml_node_reader {

  public:
	policy_action();
		
	policy_action(const policy_action &rhs);
	
	~policy_action();

	/**
	 * This function assumes that the pointer is at the beginning of a 
	 * policy action. When the function ends the pointer can be
	 * at the beginning of the next object or at the end of the document.
	 */ 
	int read_from_xml(xmlTextReaderPtr node);
	
	void set_action_mapping(std::string app, policy_action_mapping _mapping);
	
	bool operator==(const policy_action &rhs) const;
	
	bool operator!=(const policy_action &rhs) const;
	
	std::string get_name() const;
	 
	typedef std::map<std::string, policy_action_mapping>::const_iterator const_iterator;
	const_iterator begin() const throw() { return action_mappings.begin(); }
	const_iterator end() const throw() { return action_mappings.end(); }
    
  private:
	std::map<std::string, policy_action_mapping> action_mappings;
	std::string action;
	
	static std::string id_str;
	
};

} // namespace mnslp

#endif // MNSLP__POLICY_ACTION_H