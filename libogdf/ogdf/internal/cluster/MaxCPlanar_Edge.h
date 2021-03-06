/*
 * $Revision: $
 * 
 * last checkin:
 *   $Author: chimani $ 
 *   $Date: 2008-05-28 20:22:00 +1000 (Wed, 28 May 2008) $ 
 ***************************************************************/
 
/** \file
 * \brief Declaration of the variable class for the Branch&Cut algorithm
 * for the Maximum C-Planar SubGraph problem
 * 
 * \author Mathias Jansen
 * 
 * 
 * \par License:
 * This file is part of the Open Graph Drawing Framework (OGDF).
 * Copyright (C) 2005-2007
 * 
 * \par
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * Version 2 or 3 as published by the Free Software Foundation
 * and appearing in the files LICENSE_GPL_v2.txt and
 * LICENSE_GPL_v3.txt included in the packaging of this file.
 *
 * \par
 * In addition, as a special exception, you have permission to link
 * this software with the libraries of the COIN-OR Osi project
 * (http://www.coin-or.org/projects/Osi.xml), all libraries required
 * by Osi, and all LP-solver libraries directly supported by the
 * COIN-OR Osi project, and distribute executables, as long as
 * you follow the requirements of the GNU General Public License
 * in regard to all of the software in the executable aside from these
 * third-party libraries.
 * 
 * \par
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * \par
 * You should have received a copy of the GNU General Public 
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 * 
 * \see  http://www.gnu.org/copyleft/gpl.html
 ***************************************************************/

#ifndef OGDF_MAX_CPLANAR_EDGE_H
#define OGDF_MAX_CPLANAR_EDGE_H

#include <ogdf/basic/Graph_d.h>
#include <ogdf/basic/Logger.h>

#include <abacus/variable.h>

namespace ogdf {
	

class EdgeVar : public ABA_VARIABLE {
	friend class Sub;
public:
enum edgeType {ORIGINAL, CONNECT};
	
	EdgeVar(ABA_MASTER *master, double obj, edgeType eType, node source, node target);

	virtual ~EdgeVar();
		
	edge theEdge() const {return m_edge;}
	node sourceNode() const {return m_source;}
	node targetNode() const {return m_target;}
	edgeType theEdgeType() const {return m_eType;}
	//double objCoeff() const {return m_objCoeff;}
	
	void printMe(ostream& out) {
		out << "[Var: " << sourceNode() << "->" << targetNode() << " (" << ((theEdgeType()==EdgeVar::ORIGINAL)?"original":"connect") << ") ZF=" << obj() << "]";
	}
		
private:
		
	// The egde type of the variable
	edgeType m_eType;
		
	// The corresponding nodes and edge
	node m_source;
	node m_target;
	edge m_edge;
		
	// The objective function coefficient
	//double m_objCoeff; //MCh: not necc. abacus stoires that already
};

}

#endif

