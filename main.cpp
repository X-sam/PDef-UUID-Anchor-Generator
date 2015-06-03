// $RCSfile: $
// $Revision: $ $Date: $
// Auth: Samson Bonfante (bonfante@steptools.com)
// 
// Copyright (c) 1991-2015 by STEP Tools Inc. 
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <rose.h>
#include <stp_schema.h>
#include "GUID.h"
#include <iostream>

void main(int argc,char * argv[])
{
    stplib_init();

	if (argc != 2){ //Makes sure that command line has 2 arguments
		printf("Usage: %s step file\n", argv[0]);
		return;
	}

	RoseDesign * d = ROSE.findDesign(argv[1]);
	RoseP21Writer::max_spec_version(PART21_ED3);
	if (!d) return;

	RoseCursor cur;
	RoseObject * obj;

	cur.traverse(d);
	cur.domain(ROSE_DOMAIN(stp_product_definition));

	while ((obj = cur.next()) != 0){
		stp_product_definition * pd = ROSE_CAST(stp_product_definition, obj);
		std::string uuid = get_guid();
		printf("Product Definiton ID #%d \t UUID: %s\n", pd->id(),uuid.c_str());
		d->addName(uuid.c_str(), pd);
	}
	char outname[100];
	_snprintf(outname, 100, "%swithUUIDAnchors.stp", d->name());
	d->saveAs(outname);
	system("pause");

    return;
}