#include "library.h"
#include <stdio.h>

#define NUM_CHARS 256 // 2^8
// 배열의 타입은, 배열 한 칸에 저장되는 데이터의 타입
Artist* artist_directory[NUM_CHARS]; 
int num_index = 0;
Artist* find_artist(char* input_name);
void insert_node(Artist* ptr_artist, SNode* ptr_snode);
void print_artist(Artist* p);
void print_song(Song* ptr_song);


void initialize() 
{
	for (int i = 0; i < NUM_CHARS; i++)
		artist_directory[i] = NULL;
}

Artist* create_artist_instance(char* name)
{
	Artist* ptr_artist = (Artist*)malloc(sizeof(Artist));
	ptr_artist->name = name;
	ptr_artist->head = NULL;
	ptr_artist->tail = NULL;
	ptr_artist->next = NULL;

	return ptr_artist;
}

Artist* add_artist(char *name) 
{
	Artist* ptr_artist = create_artist_instance(name); 

	Artist* p = artist_directory[(unsigned char)name[0]]; // first-Node
	Artist* q = NULL;

	while (p != NULL && strcmp(p->name, name) < 0) {
		q = p;
		p = p->next;
	}

	if (p == NULL && q == NULL) { // 해당 알파벳이 empty list
		artist_directory[(unsigned char)name[0]] = ptr_artist;
	}
	else if (q == NULL) { // p를 head에 삽입
		ptr_artist->next = artist_directory[(unsigned char)name[0]];
		artist_directory[(unsigned char)name[0]] = ptr_artist;
	}
	else { // 일반적인 case: q와 p 사이에 삽입
		ptr_artist->next = p;
		q->next = ptr_artist;
	}

	return ptr_artist;
}

Song* create_song_instance(Artist* ptr_artist, char* title, char* path) {
	Song* ptr_song = (Song*)malloc(sizeof(Song));
	ptr_song->artist = ptr_artist;
	ptr_song->title = title;
	ptr_song->path = path;
	ptr_song->index = num_index;
	num_index++;

	return ptr_song;
}

 void add_song(char * artist,char *title, char *path) 
{
	// find if the artist already exists.
	 // return NULL if not exist.
	 Artist* ptr_artist = find_artist(artist);
	 if (ptr_artist == NULL) {
		 ptr_artist = add_artist(artist);
	 }

	 // add the song to the artist pointed by ptr_artist
	 Song* ptr_song = create_song_instance(ptr_artist, title, path);
	 SNode* ptr_snode = (SNode*)malloc(sizeof(SNode));

	 ptr_snode->song = ptr_song;

	 // insert node
	 insert_node(ptr_artist, ptr_snode);
}

 void insert_node(Artist* ptr_artist, SNode* ptr_snode)
 {
	
	 SNode* p = ptr_artist->head;
	 while (p != NULL && strcmp(p->song->title, ptr_snode->song->title) < 0) {
		 p = p->next;
	 }

	 // 'ptr_snode'를 이중연결리스트의 'p'노드 전에 삽입
	 // 1. empty list
	 // 2.head에 삽입
	 // 3.tail에 삽입
	 // 4.중간에 삽입
	 if (ptr_artist->head == NULL) { // empty list에 삽입
		 ptr_artist->head = ptr_snode;
		 ptr_artist->tail = ptr_snode;
	 }
	 else if(p==ptr_artist->head) { // head에 삽입
		 ptr_snode->next = ptr_artist->head;
		 ptr_artist->head->prev = ptr_snode;
		 ptr_artist->head = ptr_snode;
	 }
	 else if (p == NULL) { // tail에 삽입
		 ptr_snode->prev = ptr_artist->tail;
		 ptr_artist->tail->next = ptr_snode;
		 ptr_artist->tail = ptr_snode;
	 }
	 else {
		 ptr_snode->next = p;
		 ptr_snode->prev = p->prev;
		 p->prev->next = ptr_snode;
		 p->prev = ptr_snode;
	 }
 }

 Artist* find_artist(char* input_name) 
 {
	 // name[0](이름의 첫글자)의 첫 아티스트 
	 // name[0] : 00000000 ~ 11111111
	 
	 /* ex) name이 IU라면, 
	 name[0]는 'I'이고, 
	 artist_directory[name[0]는 
	 'I'로 시작하는 artist들의 첫 아티스트,
	 해당하는 첫 아티스트가 없었다면 NULL
	 */ 

	 Artist* p = artist_directory[(unsigned char)input_name[0]];
//	 while (p != NULL && strcmp(p->name, input_name) != 0)
	while (p != NULL && strcmp(p->name, input_name) < 0)
		 p = p->next;

	if (p != NULL && strcmp(p->name, input_name) == 0)
		return p;
	else
		return NULL;
 }

 void status()
 {
	 for (int i = 0; i < NUM_CHARS; i++) {

		 Artist* p = artist_directory[i];
		 while (p != NULL) {
			 print_artist(p);
			 p = p->next;
		 }
	 }
 }

 void print_artist(Artist* p) {
	 printf("%s\n", p->name);
	 SNode* ptr_snode = p->head;
	 while (ptr_snode != NULL) {
		 print_song(ptr_snode->song);
		 ptr_snode = ptr_snode->next;
	 }
 }

 void print_song(Song* ptr_song) {
	 printf("    %d: %s, %s\n", ptr_song->title, ptr_song->path);
 }