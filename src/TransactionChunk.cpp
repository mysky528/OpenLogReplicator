/* Buffer to handle transactions peaces
   Copyright (C) 2018-2019 Adam Leszczynski.

This file is part of Open Log Replicator.

Open Log Replicator is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as published
by the Free Software Foundation; either version 3, or (at your option)
any later version.

Open Log Replicator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
Public License for more details.

You should have received a copy of the GNU General Public License
along with Open Log Replicator; see the file LICENSE.txt  If not see
<http://www.gnu.org/licenses/>.  */

#include "TransactionChunk.h"

namespace OpenLogReplicatorOracle {

	TransactionChunk::TransactionChunk(TransactionChunk *prev, uint8_t *buffer) :
			elements(0),
			size(0),
			buffer(buffer),
			prev(prev),
			next(nullptr) {
		if (prev != nullptr)
			prev->next = this;
	}

	TransactionChunk::~TransactionChunk() {
		if (prev != nullptr)
			prev->next = next;
		if (next != nullptr)
			next->prev = prev;
	}
}
