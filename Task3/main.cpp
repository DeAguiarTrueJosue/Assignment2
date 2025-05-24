#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

int CompareBothCase(const char* number1, const char* number2) {
	int ca, cb;
	do {
		ca = *(unsigned char*)number1;
		cb = *(unsigned char*)number2;
		ca = tolower(ca);
		cb = tolower(cb);
		number1++;
		number2++;
	} while (ca == cb && ca != '\0');
	return ca - cb;
}

void toLower(char* a) {
	int ca;
	do {
		ca = *(unsigned char*)a;
		ca = tolower(ca);
		*a = ca;
		a++;
	} while (ca != '\0');
}

struct MediaItem
{
	char title[50];
	float duration;
	char mediaType[8];
	MediaItem* next;
};

MediaItem* CreateNode(char title[50], float duration, char mediaType[8]) {
	MediaItem* nextptr = (MediaItem*)malloc(sizeof(MediaItem));
	if (nextptr != nullptr)
	{
		strcpy_s(nextptr->title, title);
		nextptr->duration = duration;
		strcpy_s(nextptr->mediaType, mediaType);
		nextptr->next = nullptr;
	}
	return nextptr;
}

MediaItem* AddToPlaylist(MediaItem* head, char title[50], float duration, char mediaType[8]) {
	MediaItem* newEnd = CreateNode(title, duration, mediaType);
	MediaItem* current = head;
	if (newEnd == nullptr)
	{
		return head;
	}
	if (head == nullptr)
	{
		return newEnd;
	}
	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = newEnd;
	return head;
}

void DisplayPlaylist(MediaItem* head)
{
	MediaItem* current = head;
	MediaItem* next;

	while (current != nullptr)
	{
		next = current->next;
		printf_s("%s", current->mediaType);
		printf_s(" - %s", current->title);
		printf(" - %.2f\n", current->duration);
		current = next;
	}
}

float CalcuteDuration(MediaItem* head)
{
	MediaItem* current = head;
	MediaItem* next;

	float totalDuration = 0;

	while (current != nullptr)
	{
		next = current->next;
		totalDuration += current->duration;
		current = next;
	}
	return totalDuration;
}

MediaItem* RemoveItem(MediaItem* head, char title[50])
{
	MediaItem* current = head;

	if (!CompareBothCase(title, head->title))
	{
		current = head->next;
		free(head);
		return current;
	}

	while (CompareBothCase(title, current->next->title) && current->next->next != nullptr)
	{
		current = current->next;
	}

	if (current->next == nullptr)
	{
		return head;
	}

	MediaItem* temp = current->next;
	current->next = current->next->next;
	free(temp);
	return head;
}

void FreePlaylist(MediaItem* head)
{
	MediaItem* current = head;
	MediaItem* next;

	while (current != nullptr)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int main()
{
	MediaItem* head = nullptr;
	
	head = AddToPlaylist(head, (char*)"Sensacao espacial", 1.52f, (char*)"Music");
	head = AddToPlaylist(head, (char*)"Jogador Numero 1", 145.36f, (char*)"Movie");
	head = AddToPlaylist(head, (char*)"Science Everyday", 30.0f, (char*)"Podcast");
	head = AddToPlaylist(head, (char*)"Flores Mortas", 3.21f, (char*)"Music");

	DisplayPlaylist(head);

	printf("\n");

	printf("Total playthrought time: %.2f\n", CalcuteDuration(head));

	head = RemoveItem(head, (char*)"afwgzrsh");
	
	printf("\n");

	DisplayPlaylist(head);

	FreePlaylist(head);
	return 0;
}