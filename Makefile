RM = /bin/rm

CC = g++ -g

SRCDIR = src
OBJDIR = obj
BINDIR = bin
TSTDIR = test

TEST = testConvertor.cpp
SRCS = NumToEnglish.cpp NumToText.cpp 
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

TRGT = $(BINDIR)/converToText

$(TRGT) : $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(TSTDIR)/$(TEST) -Iinclude $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c $< -Iinclude -o $@

clean:
	$(RM) $(OBJDIR)/* $(TRGT)
