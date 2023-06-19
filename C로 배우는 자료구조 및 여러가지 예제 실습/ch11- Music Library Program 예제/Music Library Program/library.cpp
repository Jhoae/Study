#pragma warning (disable:4996)
#include "library.h"
#include "string_tools.h"

#include <stdio.h>
#include <windows.h>

#define BUFFER_LENGTH 200
#define SIZE_INDEX_TABLE 100
#define NUM_CHARS 256 // 2^8
// �迭�� Ÿ����, �迭 �� ĭ�� ����Ǵ� �������� Ÿ��

Artist* artist_directory[NUM_CHARS]; 
SNode* index_directory[SIZE_INDEX_TABLE];

int num_index = 0;

void insert_node(Artist* ptr_artist, SNode* ptr_snode);
void print_artist(Artist* p);
void print_song(Song* ptr_song);
Artist* find_artist(char* input_name);
SNode* find_snode(Artist* ptr_artist, char* title);
void insert_to_index_directory(Song* ptr_song);
void save_artist(Artist* p, FILE* fp);
void save_song(Song* ptr_song, FILE* fp);


void initialize() 
{
	for (int i = 0; i < NUM_CHARS; i++)
		artist_directory[i] = NULL;

	for (int i = 0; i < SIZE_INDEX_TABLE; i++)
		index_directory[i] = NULL;
}

void load(FILE* fp) 
{
	char buffer[BUFFER_LENGTH];
	char* name, * title, * path;

	while (1) {
		if (read_line(fp, buffer, BUFFER_LENGTH) <= 0) // ������ �� ����
			break;

		name = strtok(buffer, "#"); // ���й��� #
		if (strcmp(name, " ") == 0) // �ش� �׸��� �������� �ʴ´ٸ�
			name = NULL;
		else 
			name = strdup(name);

		title = strtok(NULL, "#"); // ���й��� #
		if (strcmp(title, " ") == 0) // �ش� �׸��� �������� �ʴ´ٸ�
			title = NULL;
		else
			title = strdup(title);

		path = strtok(NULL, "#"); // ���й��� #
		if (strcmp(path, " ") == 0) // �ش� �׸��� �������� �ʴ´ٸ�
			path = NULL;
		else
			path = strdup(path);

		//printf("%s %s %s\n", name, title, path);
		add_song(name, title, path);
	}
}

void search_song(char* artist, char* title)
{
	Artist* ptr_artist = find_artist(artist);
	if (ptr_artist == NULL) {
		printf("No Such artist exists.");
		return;
	}

	SNode* ptr_snode = find_snode(ptr_artist, title);
	if (ptr_snode != NULL) { // ����
		printf("Found:\n");
		print_song(ptr_snode->song);
	}
	else {
		printf("No such song exists.\n");
		return;
	}
}

SNode* find_snode(Artist *ptr_artist, char *title) 
{
	SNode* ptr_snode = ptr_artist->head;
	while (ptr_snode != NULL && strcmp(ptr_snode->song->title, title) < 0) // ����
		ptr_snode = ptr_snode;

	if (ptr_snode != NULL && strcmp(ptr_snode->song->title, title) == 0) // ����
		return ptr_snode;	
	else 
		return NULL;
	
}

void search_song(char *artist)
{
	Artist* ptr_artist = find_artist(artist);
	if (ptr_artist == NULL) {
		printf("No Such artist exists.");
		return;
	}
	printf("Found:\n");
	print_artist(ptr_artist);
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

	if (p == NULL && q == NULL) { // �ش� ���ĺ��� empty list
		artist_directory[(unsigned char)name[0]] = ptr_artist;
	}
	else if (q == NULL) { // p�� head�� ����
		ptr_artist->next = artist_directory[(unsigned char)name[0]];
		artist_directory[(unsigned char)name[0]] = ptr_artist;
	}
	else { // �Ϲ����� case: q�� p ���̿� ����
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
	 ptr_snode->next = NULL;
	 ptr_snode->prev = NULL;


	 // insert node
	 insert_node(ptr_artist, ptr_snode);
	 insert_to_index_directory(ptr_song);

}

 void insert_to_index_directory(Song* ptr_song)
 {
	 SNode* ptr_snode = (SNode*)malloc(sizeof(SNode));
	 ptr_snode->song = ptr_song;
	 ptr_snode->next = NULL;
	 ptr_snode->prev = NULL; // �ܹ��� ���Ḯ��Ʈ�̹Ƿ� ������� ���� ����

	 int index = ptr_song->index % SIZE_INDEX_TABLE;

	 // snode�� index_table[index]�� �ܹ��� ���� ����Ʈ�� �����մϴ�.
	 SNode* p = index_directory[index]; // indexĭ�� ù��° ���
	 SNode* q = NULL;
	 while (p != NULL && strcmp(p->song->title, ptr_song->title) < 0) {
		 q = p;
		 p = p->next;
	 }

	 // ptr_snode�� ����
	 if (q == NULL) { // add first
		 ptr_snode->next = p; // p�� ���� head���
		 index_directory[index] = ptr_snode; // ù��° ��带 ptr_snode���� ����
	 }
	 else { // add after q
		 ptr_snode->next = p;
		 q->next = ptr_snode;
	 }
	 	 


 }

 void insert_node(Artist* ptr_artist, SNode* ptr_snode)
 {
	 SNode* p = ptr_artist->head;
	 while (p != NULL && strcmp(p->song->title, ptr_snode->song->title) < 0) {
		 p = p->next;
	 }

	 // 1. empty list
	 // 2.head�� ����
	 // 3.tail�� ����
	 // 4.�߰��� ����

	 if (ptr_artist->head == NULL) { // empty list�� ����
		 ptr_artist->head = ptr_snode;
		 ptr_artist->tail = ptr_snode;
	 }
	 else if(p==ptr_artist->head) { // head�� ����
		 ptr_snode->next = ptr_artist->head;
		 ptr_artist->head->prev = ptr_snode;
		 ptr_artist->head = ptr_snode;
	 }
	 else if (p == NULL) { // tail�� ����
		 ptr_snode->prev = ptr_artist->tail;
		 ptr_artist->tail->next = ptr_snode;
		 ptr_artist->tail = ptr_snode;
	 }
	 else {	 // 'ptr_snode'�� ���߿��Ḯ��Ʈ�� 'p'��� ���� ����
		 ptr_snode->next = p;
		 ptr_snode->prev = p->prev;
		 p->prev->next = ptr_snode;
		 p->prev = ptr_snode;
	 }
 }

 Artist* find_artist(char* input_name) 
 {
	 // name[0](�̸��� ù����)�� ù ��Ƽ��Ʈ 
	 // name[0] : 00000000 ~ 11111111
	 
	 /* ex) name�� IU���, 
	 name[0]�� 'I'�̰�, 
	 artist_directory[name[0]�� 
	 'I'�� �����ϴ� artist���� ù ��Ƽ��Ʈ,
	 �ش��ϴ� ù ��Ƽ��Ʈ�� �����ٸ� NULL
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
	 printf("    %d: %s, %s\n", ptr_song->index, ptr_song->title, ptr_song->path);
 }

 SNode* find_song(int index) {
	 SNode* ptr_snode = index_directory[index % SIZE_INDEX_TABLE]; // head snode
	 while (ptr_snode != NULL && ptr_snode->song->index != index)
		 ptr_snode = ptr_snode->next; // ����

	 return ptr_snode;
 }

 void save(FILE* fp) 
 {
	 for (int i = 0; i < NUM_CHARS; i++) {
		 Artist* p = artist_directory[i];
		 while (p != NULL) {
			 save_artist(p, fp);
			 p = p->next;
		 }
	 }
 }

 void save_artist(Artist* p, FILE* fp) {
	 SNode* ptr_snode = p->head;
	 while (ptr_snode != NULL) {
		 save_song(ptr_snode->song, fp);
		 ptr_snode = ptr_snode->next;
	 }
 }

 void save_song(Song* ptr_song, FILE* fp)
 {
	 // ����#����#������ġ# ����(���� " "�� ��ü)�� text�� ����
	 if (ptr_song->artist != NULL)
		 fprintf(fp, "%s#", ptr_song->artist->name);
	 else 
		 fprintf(fp, " #");

	
	 if (ptr_song->title != NULL)
		fprintf(fp, "%s#", ptr_song->title);
	else
		fprintf(fp, " #");

	 if (ptr_song->path != NULL)
		 fprintf(fp, "%s#\n", ptr_song->path);
	 else
		 fprintf(fp, " #\n");


 }

 void play(int index)
{
	 SNode* ptr_snode = find_song(index);
	 if (ptr_snode == NULL) {
		 printf("No such song exists.\n");
	 }
		
	 // chatGPT �����ؼ� ����
	 // ShellExecute(GetDesktopWindow(), "open", ptr_snode->song->path, NULL, NULL, SW_SHOW);
	 wchar_t wpath[MAX_PATH];
	 MultiByteToWideChar(CP_UTF8, 0, ptr_snode->song->path, -1, wpath, MAX_PATH);
	 ShellExecuteW(GetDesktopWindow(), L"open", wpath, NULL, NULL, SW_SHOW);
	 ShellExecuteW(GetDesktopWindow(), L"open", wpath, NULL, NULL, SW_SHOW);

}