}
	return 0;
	printf("Success! MaxValue: %d\n",maxValue);		

	free(base);
	}
		free(items[i]);
//		printf("%f\n",items[i]->density);
	for (i = 0;i<totalItems;i++){
	i = 0;
	/* Cleanup */


	}
		}
			}		
				}	
					
					}
						printf("Reached the bottom, no new spine: %d & %d\n",workingNode->index, totalItems);
					} else {

						printf("New spine, level: %d\n",workingNode->index);
						currentSpine = vert;
						currentSpine->next = vert;
						struct Bone * vert = createBone(currentSpine, NULL, workingNode);
						printf("\n!!!\nDo I ever get called?\n!!!\n");
					if ((workingNode->index != totalItems-1)&&(workingNode->selected==1)){ // Is this correct?
					printf("Working node selected: %d\n",workingNode->selected);
					// Add a new spine at this node, if not at bottom - and we didn't take a right!

					workingNode = next; // Move down the tree. 
					next->last = workingNode;
					}
						workingNode->left = next;
					} else {
						workingNode->right = next;
					if ( next->selected == 0){ // Add the node in the right direction.

					}
						printf("\n###\nActually updated maxValue: %d\n###\n",maxValue);
						maxValue = maxInt(next->estimate, maxValue); 
					if ( next->index == totalItems-1) { // must be on last level to actually change max value.
					
					printf("Index: %d, totalItems %d\n###\n",workingNode->index,totalItems);
					printf("Value: %d, room: %d\n",workingNode->value,workingNode->room);
				} else { // We can continue.
					break;
					free(next);
					printf("Not adding, estimate (%f), less than maxValue (%d)\n",next->estimate,maxValue);
				} else if (next->estimate < maxValue){ // We don't need to continue, we're too low!
					break; // Stop looping from here - hopefully this doesn't stop the while loop?
					free(next);

					printf("Overflowed in vertebra: %d\n",next->room);
				if ( next->room < 0){ // If we've overflowed - only a problem if we've gone left, perhaps we should add the check there?
				printf("Before conditional: value: %d, room: %d, estimate: %f, maxValue: %d\n",next->value,next->room,next->estimate,maxValue);



				}
					next = createNode(workingNode->index+1,1,workingNode->value + workingItem->value, workingNode->room-workingItem->weight,workingNode->estimate,workingNode, NULL, NULL, workingItem);
					printf("\n\nThis is gettin' called!\n\n");
				} else { // Else left.
					next = createNode(workingNode->index+1,0,workingNode->value, workingNode->room, workingNode->estimate-workingItem->value,workingNode, NULL, NULL, workingItem);
					printf("Creating a left node: i: %d, index: %d\n",i,workingNode->index);
				if (i == ((workingNode->index)+1)){ // We need to go right...

				workingItem = items[workingNode->index + 1];


				printf("In for loop, i: %i, index: %d\n",i,workingNode->index);
			for (i = workingNode->index+1; i<totalItems;i++){
			printf("Begin for loop: init i @: %d\n",workingNode->index+1);
//			next = createNode(i,1, current->value + cItem->value, current->room - cItem->weight, current->estimate, current, NULL, NULL, cItem);
			
			workingNode = workingSpine->node;

		if (currentSpine->node->estimate >= maxValue){ // We only need to use the vertebra if its estimate is feasible.
//		printf("This is a check to make sure we continue after an overflow in vertebra.");

		}
			currentSpine->next = NULL;
		if (currentSpine != NULL){
		currentSpine = workingSpine->last; // Effectively remove it.
		workingSpine = currentSpine; // Use it wto work with


		printf("\n$$$\n$$$\nWe begin at: %d\n$$$\n$$$\n",currentSpine->node->index);

	while (currentSpine->last != NULL){ // While we still have spine..


	spineBase->last = dummySpine;
	struct Bone *dummySpine = createBone(NULL, NULL, base);

	printf("spineBase->value: %d\n",spineBase->node->value);
	
	struct Item *workingItem;
	struct Node *workingNode;
	struct Bone *workingSpine;

	*/ 
	* ETc etc.
	* Go ONE right from each vert and then go left all the way ('til non feasible) Adding vertebrae as we go as needed...
	* If the vertebra's node is still feasible: 
	* remove the vertebra
	* So, going backwards through the spine linked list (until we reach the base - current->last == NULL) 
	/** We should now have a max value for the all left branch, as well as have built a spine.
	printf("Starting 'second wave'\n");


	}
		}
			printf("New spine, node with room: %i\n",currentSpine->node->room);

			currentSpine = vert; // make it the new currentSpine;
			currentSpine->next = vert; // Add it to the spine...
			struct Bone * vert = createBone(currentSpine, NULL, current); // Create a new vertebra....

			current = next; // Move down the tree.			
			next->last = current; // Remember its parent...
			current->left = next; // Add the node to the tree. 


			}
				printf("\n###\nActually updated maxValue: %d\n###\n",maxValue);
				maxValue = maxInt(current->estimate, maxValue);
			if(i ==totalItems-1) { // must be on last leaf to actually change the value...
		} else { // There is room still - add the item.
			break; // stop looping through the items.
			free(next); // This is no longer needed.

			printf("Overflowed: %d\n",next->room);
//			printf("Overflowed with failed value: %i, old value: %i\n",(int)(current->estimate),(int)(maxInt));
		if ( next->room < 0){ // We're out of room with this item! Don't continue. 


		next = createNode(i,1, current->value + cItem->value, current->room - cItem->weight, current->estimate, current, NULL, NULL, cItem);
		struct Item *cItem = items[i];
	for (i = 0; i<totalItems;i++){
	/* Wave 1 - to get first value and to set up 'vertebrae' */

	struct Bone *currentSpine = spineBase;
	struct Bone *spineBase = createBone(NULL, NULL, base);

	int maxValue = 0;
//	printf("%d\n",base->room);
	struct Node *next;
	struct Node *current = base;
	struct Node *base = createNode(-1,0,0,capacity,optValue,NULL,NULL,NULL,NULL);

	/** Ready to make the TREE! **/

	}
		exit(3);
		//printf("Error scanning all our items! We only got %i.\n",itemCount+1);
	if ((itemCount) != totalItems){

	};
		itemCount++;
		items[itemCount] = thisItem;	
		struct Item *thisItem = createItem(intIndex, intValue, intWeight, intDensity);

		//printf("intDensity: %f\n",intDensity);
		//printf("intWeight: %d\n", intWeight);
		//printf("intValue: %d\n",intValue);
		//printf("intIndex: %d\n",intIndex);


		intDensity = strtof(thisDensity,NULL);
		intWeight = strtol(thisWeight,&strtolError,10);

		intValue = strtol(thisValue,&strtolError,10);
		printf("%s\n",thisValue);
		intIndex = strtol(thisIndex, &strtolError,10);

		saveptr = NULL;
		thisDensity = strtok_r(NULL, " ", &saveptr);
		thisWeight = strtok_r(NULL, " ", &saveptr);
		thisValue = strtok_r(NULL, " ", &saveptr);
		thisIndex = strtok_r(line, " ", &saveptr);

		float intDensity;
		int intWeight;
		int intValue;
		int intIndex;
			
		char* thisDensity;
		char* thisWeight;
		char* thisValue;
		char* thisIndex;
	while (fgets(line, sizeof(line), file)) {
	/* Scan all items into the items[] array. */

	int itemCount = 0;

	struct Item *items[totalItems];// = (struct Item *) malloc(sizeof(struct Item)*totalItems);
	int totalItems = strtol(line,&strtolError,10);
	fgets(line, sizeof(line), file);

	int capacity = strtof(line,NULL);
	fgets(line,sizeof(line),file);

//	printf("Opt Value: %f\n",optValue);
	float optValue = strtof(line,NULL);
	//printf("%s",line);
	fgets(line, sizeof(line),file);

	char *saveptr;
	char line[10000];
	}
		exit(2);
		printf("File invalid!\n");
	if (file == NULL){
	FILE* file = fopen(fileLoc,"r");
	char* fileLoc = argv[1];

	}
		exit(1);
		printf("Not enough args!\n");
	if (!(argc>1)){

	char *strtolError;
	int i;
	
	printf("Starting the function?\n");
	
int main(int argc, char* argv[]){


}
	}
		return b;
	} else {
		return a;
	if (a > b){
int maxInt(int a, int b){

}
	return bone;
	bone->node = node;
	printf("Bone created, node->value: %d\n",node->value);
	bone->next = next;
	bone->last = last;
	struct Bone *bone = (struct Bone *) malloc(sizeof(struct Bone));
struct Bone *createBone(struct Bone *last,struct Bone *next, struct Node * node){

}
	return node;
	node->item = item;
	node->right = right;
	node->left = left;
	node->last = last;
	node->estimate = estimate;
	node->room = room;
	node->value = value;
	node->selected = selected;
	node->index = index;
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
struct Node *createNode(int index, int selected, int value, int room, float estimate, struct Node *last, struct Node *left, struct Node *right, struct Item *item){

}
	return item;  // Item is NOT freed!
	item->density = density;
	item->weight = weight;
	item->value = value;
	item->index = index;
	struct Item *item = (struct  Item *) malloc(sizeof(struct Item));
//	printf("Creating item with density %d\n",density);
struct Item *createItem(int index, int value, int weight, float density){
**/
* See: http://stackoverflow.com/questions/8047261/what-does-dot-mean-in-a-struct-initializer
/**  Function for creating items - an initializer. Is this necessary?




};
	
	struct Node * node;
		
	struct Bone * next; 
	struct Bone * last;

struct Bone {

};
	struct Item *item;

	struct Node *right;
	struct Node *left;
	struct Node *last;
	
	float estimate;
	int room;
	int value;
	
	int selected;

	int index;

struct Node {

};
	float density;
	int weight;
	int value;
	int index;
struct Item {

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
