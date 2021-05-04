
  std::string dirname;
  std::string argvString(argv[1]);
  std::cout << argvString << std::endl;
  DIR *directory;
  struct dirent *file;
  FILE *a;
  char ch;

  directory = opendir(argv[1]);

  while ((file = readdir(directory)) != NULL)
  {
    printf("%s\n", file->d_name);
    std::cout << file->d_name << std::endl;
  }

  closedir(directory);

  return 1;