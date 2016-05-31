// Implementation of the Bellman-Ford algorithm in C (unlimited vertices)
// Grayson Pike, May 2016

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_VERTICES 6
#define NUM_PATHS 8

struct path {
	int start;
	int end;
	int cost;
};

int total_costs[NUM_VERTICES];
struct path paths[NUM_PATHS];

void init_graph() {
	total_costs[0] = 0;
	for(int i = 1; i < NUM_VERTICES; i++) {
		total_costs[i] = INT_MAX;
	}
	paths[0] = (struct path){0, 1, 10};
	paths[1] = (struct path){0, 5, 8};
	paths[2] = (struct path){1, 3, 2};
	paths[3] = (struct path){2, 1, 1};
	paths[4] = (struct path){3, 2, -2};
	paths[5] = (struct path){4, 1, -4};
	paths[6] = (struct path){4, 3, -1};
	paths[7] = (struct path){5, 4, 1};
}

// Return true if path is changed, false otherwise
bool check_path(struct path *p) {
	if(total_costs[p->start] != INT_MAX) {
		if(total_costs[p->end] == INT_MAX) {
			total_costs[p->end] = total_costs[p->start] + p->cost;
			return true;
		} else if(total_costs[p->start] + p->cost < total_costs[p->end]) {
			total_costs[p->end] = total_costs[p->start] + p->cost;
			return true;
		}
	}
	return false;
}

// TODO fix to allow unreachable vertices
void print_costs() {
	printf("Vertex\tCost\n");
	for(int i = 0; i < NUM_VERTICES; i++) {
		printf("%d\t%d\n", i, total_costs[i]);
	}
}
			
int main() {
	init_graph();
	bool changed = true;
	while(changed) {
		changed = false;
		for(int i = 0; i < NUM_VERTICES; i++) {
			for(int j = 0; j < NUM_PATHS; j++) {
				if(paths[j].start == i) {
					if(check_path(&paths[j])) {
						changed = true;
					}
				}
			}
		}
	}
	print_costs();
}
							
