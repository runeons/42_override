
void set_msg(char *buffer)

{
  undefined8 message[128];
  
  bzero(message, 128);
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets((char *)message, 1024, stdin);
  strncpy(buffer, (char *)message, (long)*(int *)(buffer + 180));
  return;
}

void set_username(long buffer)

{
  undefined8 username[17];
  int i;
  
  bzero(username, 16);
  puts(">: Enter your username");
  printf(">>: ");
  fgets((char *)username, 128, stdin);
  for (i = 0; (i < 41 && (*(char *)((long)username + (long)i) != '\0')); i = i + 1) {
    *(undefined *)(buffer + 140 + (long)i) = *(undefined *)((long)username + (long)i);
  }
  printf(">: Welcome, %s", buffer + 140);
  return;
}

void handle_msg(void)

{
  char buffer[140];
  undefined8 local_3c;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  undefined8 local_1c;
  undefined4 local_14;
  
  local_3c = 0;
  local_34 = 0;
  local_2c = 0;
  local_24 = 0;
  local_1c = 0;
  local_14 = 140;
  set_username((long)buffer);
  set_msg(buffer);
  puts(">: Msg sent!");
  return;
}

int main(void)
{
  puts(
      "--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n- -------------------------------------------"
      );
  handle_msg();
  return 0;
}