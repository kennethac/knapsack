#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Item {
	int index;
	int value;
	int weight;
	float density;
};

struct Node {

	int index;

	int selected;
	
	int value;
	int room;
	float estimate;
	
	struct Node *last;
	struct Node *left;
	struct Node *right;

	struct Item *item;
};

struct Bone {

	struct Bone * last;
	struct Bone * next; 
		
	struct Node * node;
	
};




/**  Function for creating items - an initializer. Is this necessary?
* See: http://stackoverflow.com/questions/8047261/what-does-dot-mean-in-a-struct-initializer
**/
struct Item *createItem(int index, int value, int weight, float density){
//	printf("Creating item with density %d\n",density);
	struct Item *item = (struct  Item *) malloc(sizeof(struct Item));
	item->index = index;
	item->value = value;
	item->weight = weight;
	item->density = density;
	return item;  // Item is NOT freed!
}

struct Node *createNode(int index, int selected, int value, int room, float estimate, struct Node *last, struct Node *left, struct Node *right, struct Item *item){
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
	node->index = index;
	node->selected = selected;
	node->value = value;
	node->room = room;
	node->estimate = estimate;
	node->last = last;
	node->left = left;
	node->right = right;
	node->item = item;
	return node;
}

struct Bone *createBone(struct Bone *last,struct Bone *next, struct Node * node){
	struct Bone *bone = (struct Bone *) malloc(sizeof(struct Bone));
	bone->last = last;
	bone->next = next;
	printf("Bone created, node->value: %d\n",node->value);
	bone->node = node;
	return bone;
}

int maxInt(int a, int b){
	if (a > b){
		return a;
	} else {
		return b;
	}
}


int main(int argc, char* argv[]){
	
	printf("Starting the function?\n");
	
	int i;
	char *strtolError;

	if (!(argc>1)){
		printf("Not enough args!\n");
		exit(1);
	}

	char* fileLoc = argv[1];
	FILE* file = fopen(fileLoc,"r");
	if (file == NULL){
		printf("File invalid!\n");
		exit(2);
	}
	char line[25];
	char *saveptr;

	fgets(line, sizeof(line),file);
	//printf("%s",line);
	float optValue = strtof(line,NULL);
//	printf("Opt Value: %f\n",optValue);

	fgets(line,sizeof(line),file);
	int capacity = strtof(line,NULL);

	fgets(line, sizeof(line), file);
	int totalItems = strtol(line,&strtolError,10);
	struct Item *items[totalItems];// = (struct Item *) malloc(sizeof(struct Item)*totalItems);

	int itemCount = 0;

	/* Scan all items into the items[] array. */
	while (fgets(line, sizeof(line), file)) {
		char* thisIndex;
		char* thisValue;
		char* thisWeight;
		char* thisDensity;
			
		int intIndex;
		int intValue;
		int intWeight;
		float intDensity;

		thisIndex = strtok_r(line, " ", &saveptr);
		thisValue = strtok_r(NULL, " ", &saveptr);
		thisWeight = strtok_r(NULL, " ", &saveptr);
		thisDensity = strtok_r(NULL, " ", &saveptr);
		saveptr = NULL;

		intIndex = strtol(thisIndex, &strtolError,10);
		intValue = strtol(thisValue,&strtolError,10);
		intWeight = strtol(thisWeight,&strtolError,10);
		intDensity = strtof(thisDensity,NULL);


		//printf("intIndex: %d\n",intIndex);
		//printf("intValue: %d\n",intValue);
		//printf("intWeight: %d\n", intWeight);
		//printf("intDensity: %f\n",intDensity);

		struct Item *thisItem = createItem(intIndex, intValue, intWeight, intDensity);
		items[itemCount] = thisItem;	
		itemCount++;
	};

	if ((itemCount) != totalItems){
		//printf("Error scanning all our items! We only got %i.\n",itemCount+1);
		exit(3);
	}

	/** Ready to make the TREE! **/

	struct Node *base = createNode(-1,0,0,capacity,optValue,NULL,NULL,NULL,NULL);
	struct Node *current = base;
	struct Node *next;
//	printf("%d\n",base->room);
	int maxValue = 0;

	struct Bone *spineBase = createBone(NULL, NULL, base);
	struct Bone *currentSpine = spineBase;

	// Get to the bottom


/*** KILL THE WAVES! (for now)
	/* Wave 1 - to get first value and to set up 'vertebrae' */
	for (i = 0; i<totalItems;i++){
		struct Item *cItem = items[i];
		next = createNode(i,1, current->value + cItem->value, current->room - cItem->weight, current->estimate, current, NULL, NULL, cItem);

		if ( next->room < 0){ // We're out of room with this item! Don't continue. 
			maxValue = maxInt(current->estimate, maxValue);
//			printf("Overflowed with failed value: %i, old value: %i\n",(int)(current->estimate),(int)(maxInt));
			printf("Overflowed: %d\n",next->room);
			free(next); // This is no longer needed.
			break; // stop looping through the items.
		} else { // There is room still - add the item.
			current->left = next; // Add the node to the tree. 
			next->last = current; // Remember its parent...
			current = next; // Move down the tree.			

			struct Bone * vert = createBone(currentSpine, NULL, current); // Create a new vertebra....
			currentSpine->next = vert; // Add it to the spine...
			currentSpine = vert; // make it the new currentSpine;

			printf("New spine, node with room: %i\n",currentSpine->node->room);
		}
	}

	printf("base->left-> left: value: %d, room: %d, estimate: %f\n",base->left->left->value,base->left->left->room,base->left->left->estimate);

	printf("Starting 'second wave'\n");
	/** We should now have a max value for the all left branch, as well as have built a spine.
	* So, going backwards through the spine linked list (until we reach the base - current->last == NULL) 
	* remove the vertebra
	* If the vertebra's node is still feasible: 
	* Go ONE right from each vert and then go left all the way ('til non feasible) Adding vertebrae as we go as needed...
	* ETc etc.
	*/ 

	struct Bone *workingSpine;
	struct Node *workingNode;
	struct Item *workingItem;
	
	printf("spineBase->value: %d\n",spineBase->node->value);

	while (currentSpine->last != NULL){ // While we still have spine..
		workingSpine = currentSpine; // Use it wto work with
		currentSpine = workingSpine->last; // Effectively remove it.
		currentSpine->next = NULL;

//		printf("This is a check to make sure we continue after an overflow in vertebra.");
		if (currentSpine->node->estimate >= maxValue){ // We only need to use the vertebra if its estimate is feasible.

			workingNode = workingSpine->node;
			
//			next = createNode(i,1, current->value + cItem->value, current->room - cItem->weight, current->estimate, current, NULL, NULL, cItem);

			for (i = workingNode->index+1; i<totalItems;i++){
				printf("In for loop, i: %i\n",i);


				workingItem = items[workingNode->index + 1];

				if (i == workingNode->index+1){ // We need to go right...
					next = createNode(workingNode->index+1,0,workingNode->value, workingNode->room, workingNode->estimate-workingItem->value,workingNode, NULL, NULL, workingItem);
				} else { // Else left.
					next = createNode(workingNode->index+1,1,workingNode->value + workingItem->value, workingNode->room-workingItem->weight,workingNode->estimate,workingNode, NULL, NULL, workingItem);
				}

// Seems correct		printf("Before conditional: value: %d, room: %d, estimate: %f, maxValue: %d\n",next->value,next->room,next->estimate,maxValue);
				if ( next->room < 0){ // If we've overflowed - only a problem if we've gone left, perhaps we should add the check there?
					maxValue = maxInt(workingNode->estimate, maxValue); 
					printf("Overflowed in vertebra: %d\n",next->room);
					free(next);
					break; // Stop looping from here - hopefully this doesn't stop the while loop?
				} else if (next->estimate < maxValue){ // We don't need to continue, we're too low!
					printf("Not adding, estimate (%f), less than maxValue (%d)\n",next->estimate,maxValue);
					free(next);
					break;
				} else { // We can continue.

					if ( next->selected == 0){ // Add the node in the right direction.
						workingNode->right = next;
					} else {
						workingNode->left = next;
					}
					next->last = workingNode;
					workingNode = next; // Move down the tree. 

					// Add a new spine at this node, if not at bottom - and we didn't take a right!
					if ((workingNode->index != totalItems-1)&&(workingNode->selected==1)){ // Is this correct?
						struct Bone * vert = createBone(currentSpine, NULL, workingNode);
						currentSpine->next = vert;
						currentSpine = vert;
						printf("New spine, level: %d\n",workingNode->index);

					} else {
						printf("Reached the bottom, no new spine: %d & %d\n",workingNode->index, totalItems);
					}
					
				}	
			}		
		}
	}
**/

	/* Cleanup */
	i = 0;
	for (i = 0;i<totalItems;i++){
//		printf("%f\n",items[i]->density);
		free(items[i]);
	}
	free(base);

	printf("Success!\n");		
	return 0;
}
