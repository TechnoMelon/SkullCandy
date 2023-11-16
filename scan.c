#include <stdio.h>
#include <stdlib.h>
int main() {
int total_tracks = 200;
int current_track = 100;
int tracks[total_tracks];
int n, i, head_movement = 0;
printf("Enter the number of tracks to visit: ");
scanf("%d", &n);
printf("Enter the track numbers to visit:\n");
for (i = 0; i < n; i++) {
scanf("%d", &tracks[i]);
}
int direction;
printf("Enter the initial direction (0 for left, 1 for right): ");
scanf("%d", &direction);
if (direction == 0) {
printf("Moving left.\n");
} else if (direction == 1) {
printf("Moving right.\n");
} else {
printf("Invalid direction input. Exiting...\n");
return 1;
}
// Sort the tracks in ascending order
for (i = 0; i < n; i++) {
for (int j = i + 1; j < n; j++) {
if (tracks[i] > tracks[j]) {
int temp = tracks[i];
tracks[i] = tracks[j];
tracks[j] = temp;
}
}
}
if (direction == 0) {
// Scan left
for (i = n - 1; i >= 0; i--) {
if (tracks[i] < current_track) {
printf("Moving from track %d to track %d\n", current_track, tracks[i]);
head_movement += abs(current_track - tracks[i]);
current_track = tracks[i];
}
}
// Go to the left end
printf("Moving from track %d to track 0\n", current_track);
head_movement += current_track;current_track = 0;
// Scan right
for (i = 0; i < n; i++) {
if (tracks[i] > current_track) {
printf("Moving from track %d to track %d\n", current_track, tracks[i]);
head_movement += abs(current_track - tracks[i]);
current_track = tracks[i];
}
}
} else if (direction == 1) {
// Scan right
for (i = 0; i < n; i++) {
if (tracks[i] > current_track) {
printf("Moving from track %d to track %d\n", current_track, tracks[i]);
head_movement += abs(current_track - tracks[i]);
current_track = tracks[i];
}
}
// Go to the right end
printf("Moving from track %d to track %d\n", current_track, total_tracks - 1);
head_movement += abs(current_track - (total_tracks - 1));
current_track = total_tracks - 1;
// Scan left
for (i = n - 1; i >= 0; i--) {
if (tracks[i] < current_track) {
printf("Moving from track %d to track %d\n", current_track, tracks[i]);
head_movement += abs(current_track - tracks[i]);
current_track = tracks[i];
}
}
}
printf("Total head movement: %d tracks\n", head_movement);
return 0;
}
