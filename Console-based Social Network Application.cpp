#include<iostream>
#include<fstream>

using namespace std;

class helper
{
public:
	static int stringlenght(char* str)
	{
		int stringlen = 0;
		for (char* temp = str; *temp != '\0'; temp++)
			stringlen++;

		return stringlen;
	}
	static char* getstringfrombuffer(char* buffer)
	{
		//this function takes a string
		// counts its characters upto null
		// creates a c-string of counted size
		// deep copies the the contents of original string into new size optimzed string
		// returns the new optimized string
		int strlen = stringlenght(buffer);
		char* str = 0;

		if (strlen > 0)
		{
			str = new char[strlen + 1];
			char* tempdest = str;

			for (char* tempsrc = buffer; *tempsrc != '\0'; )
			{
				*tempdest++ = *tempsrc++;
			}
			*tempdest = '\0';
		}
		return str;
	}
	static bool CompareString(char* arr1, char* arr2)
	{
		//compares two strings character by character according to ascii values
		int i = 0;
		while (arr2[i] != '\0')
		{
			if (arr1[i] != arr2[i])
			{
				return 0;
			}
			i++;
		}
		return true;
	}
	static char* int_to_char(int num)
	{
		int count = 0;
		int n = num, inc = 10;

		while (n != 0)
		{
			n /= 10;
			count += 1;

		}
		char* arr = new char[count + 1];
		int i;
		for (i = count - 1; i >= 0; i--)
		{
			arr[i] = (num % inc) + '0';
			num /= 10;
		}
		arr[count] = '\0';
		return arr;
	}
	static char* Concatenate(char* strOne, char* strTwo)
	{
		int i, j = 0;
		for (i = 0; strOne[i] != '\0'; i++)
			j++;
		for (i = 0; strTwo[i] != '\0'; i++)
		{
			strOne[j] = strTwo[i];
			j++;
		}
		strOne[j] = '\0';
		strOne = helper::getstringfrombuffer(strOne);
		return strOne;
	}
	static void ShowLine()
	{
		cout << "-------------------------------------------------------------------------------------------" << endl;
	}
};

template<class  myClass>
void Deallocate(myClass** List, int total)
{
	for (int i = 0; i < total; i++)
		delete List[i];
	delete[]List;
}

class object;
class date;
class Activity;
class comment;
class memory;
class user;
class page;
class post;

class facebook;



class object
{
	char* id;

public:
	object()
	{
		id = nullptr;
	}
	~object()
	{
		if (id != 0)
			delete[]id;
	}
	virtual void PrintName() {}
	virtual void PrintNameOnly() {}
	virtual void SetPost(post*& newpost) {}
	char* GetID() { return id; }
	void SetId(char* ID) { id = helper::getstringfrombuffer(ID); }
};

class date
{
	int day;
	int month;
	int year;
	static date currentdate;
public:
	date(int d = 0, int m = 0, int y = 0)
	{
		day = d;
		month = m;
		year = y;
	}
	~date() {}
	void PrintDate()
	{
		cout << "(" << day << "/" << month << "/" << year << ")" << endl;
	}
	void SetDate(int _day, int _month, int _year)
	{
		day = _day;
		month = _month;
		year = _year;
	}
	void ReadDateFromFile(ifstream& fin)
	{
		fin >> day;
		fin >> month;
		fin >> year;
	}
	int GetDay() { return day; }
	int GetMonth() { return month; }
	int GetYear() { return year; }
	static void SetCurrentDate(int d, int m, int y)
	{
		currentdate.day = d;
		currentdate.month = m;
		currentdate.year = y;
	}
	static date GetCurrentDate() { return currentdate; }
	bool operator ==(date rhs)
	{
		if (day == rhs.day && month == rhs.month && year == rhs.year)
			return true;
		else
			return false;
	}
};
date date::currentdate;

class Activity
{
	int type;
	char* value;
public:
	Activity()
	{
		type = 0;
		value = nullptr;
	}
	~Activity()
	{
		if (value)
			delete value;
	}

	void ReadActvityForPostFromFile(ifstream& fin)
	{
		fin >> type;
		char buffer[50] = { '\0' };

		fin.getline(buffer, 50);
		value = helper::getstringfrombuffer(buffer);
	}
	void PrintActivity()
	{
		if (type == 1)
			cout << " is feeling ";
		else if (type == 2)
			cout << " thinking about ";
		else if (type == 3)
			cout << " is making ";
		else if (type == 4)
			cout << " is celebrating ";

		cout << value << endl;
	}
};

class comment
{
	char* ID;
	char* content;
	object* CommentBy;
public:
	comment()
	{
		ID = nullptr;
		CommentBy = nullptr;
		content = nullptr;
	}
	void SetId(char* _id)
	{
		ID = helper::getstringfrombuffer(_id);
	}
	void SetCommentBy(object* commentby)
	{
		CommentBy = commentby;
	}
	void SetText(char* text)
	{
		content = helper::getstringfrombuffer(text);
	}

	char* GetId() { return ID; }
	char* GetContent() { return content; }
	object* GetCommentBy() { return CommentBy; }

	void PrintComments()
	{
		cout << "\t";
		CommentBy->PrintNameOnly();
		cout << " wrote :  \"" << content << "\"" << endl;
	}
	~comment()
	{
		if (ID != nullptr)
			delete[]ID;

		if (content != nullptr)
			delete[]content;
	}
};

class post : public object
{
	int type;
	char* ID;
	char* text;
	int totallikes;
	int totalcomments;
	date DatePosted;
	Activity* activity;
	object* sharedby;
	object** likedBy;
	comment** allcomments;
public:
	post()
	{
		type = totallikes = totalcomments = 0;
		ID = nullptr;
		text = nullptr;
		activity = nullptr;

		sharedby = nullptr;
		likedBy = nullptr;

		allcomments = nullptr;
		allcomments = new comment * [10];

		for (int i = 0; i < 10; i++)
		{
			allcomments[i] = nullptr;
		}
	}
	virtual ~post()
	{
		if (ID != 0)
			delete[]ID;

		if (text != 0)
			delete[]text;

		if (activity != 0)
			delete activity;

		if (sharedby != 0)
			delete sharedby;

		if (likedBy != 0)
			delete[] likedBy;

		if (allcomments != 0)
			for (int i = 0; i < 10; i++)
				delete allcomments[i];

	}

	void ReadPostFromFile(ifstream& fin)
	{
		char buffer[100] = { '\0' };

		fin >> type;
		fin >> buffer;
		ID = helper::getstringfrombuffer(buffer);

		DatePosted.ReadDateFromFile(fin);

		fin.ignore();

		fin.getline(buffer, 100);
		text = helper::getstringfrombuffer(buffer);

		if (type == 2)
		{
			activity = new Activity;
			activity->ReadActvityForPostFromFile(fin);
		}

	}
	void SetDate(date Date)
	{
		DatePosted = Date;
	}
	void SetSharedBy(object* id)
	{
		if (sharedby == nullptr)
			sharedby = id;

	}
	void SetComments(comment*& _comments)
	{
		if (totalcomments <= 10)
		{
			for (int i = 0; i < 10; i++)
			{
				if (allcomments[i] == NULL)		//if index is not previously used it will poit it to the desired object
				{
					allcomments[i] = _comments;
					break;
				}
			}
		}
		else
			cout << "\nMaximum comments Have Been added\n";
	}
	void SetLikedBy(object*& liker)
	{
		if (likedBy == 0)
		{
			likedBy = new object * [10];

			for (int i = 0; i < 10; i++)
			{
				likedBy[i] = 0;
			}
		}

		if (totallikes <= 10)
		{
			for (int i = 0; i < totallikes; i++)
			{
				if (likedBy[i] == NULL)
				{
					if (likedBy[i] != liker)
					{
						likedBy[i] = liker;
						totallikes++;
						break;
					}
				}
			}
		}
		else
			cout << "\nMaximum Llikes Have Been Liked\n";
	}
	void SetText(char* _text)
	{
		text = helper::getstringfrombuffer(_text);
	}
	virtual void SetValues(post* postptr, char* posttext, object* userPtr, char* id) {}

	void likeIncrement() { totallikes++; }
	void CommentIncrement() { totalcomments++; }

	date GetPostdate() { return DatePosted; }
	object* GetPostby() { return sharedby; }
	char* GetID() { return ID; }

	void AddComment(comment* _comment)
	{

		for (int i = 0; i < 10; i++)
		{
			if (allcomments[i] == nullptr)
			{
				allcomments[i] = new comment;
				allcomments[i]->SetId(_comment->GetId());
				allcomments[i]->SetText(_comment->GetContent());
				allcomments[i]->SetCommentBy(_comment->GetCommentBy());
				break;
			}
		}
	}

	void ViewLikedList()
	{
		cout << "\nPost liked by :\n" << endl;
		for (int i = 0; i < 10; i++)
		{
			if (likedBy[i] != nullptr)
			{
				likedBy[i]->PrintName();
				cout << endl;
			}
		}
	}
	void ViewPost()
	{
		cout << "--";
		sharedby->PrintNameOnly();

		if (type == 2)
			activity->PrintActivity();
		else cout << " shared ";
		cout << " \"" << text << "\"\t";

		DatePosted.PrintDate();

		for (int i = 0; allcomments[i] != nullptr; i++)
		{
			if (allcomments[i] != 0)
				allcomments[i]->PrintComments();

		}
	}
};

class memory : public post
{
	post* sharedPost;

public:
	memory()
	{
		sharedPost = nullptr;
	}


	void SetValues(post* postptr, char* posttext, object* userPtr, char* id)
	{
		sharedPost = postptr,

			this->SetId(id);
		this->SetText(posttext);
		this->SetSharedBy(userPtr);
		this->SetDate(date::GetCurrentDate());
	}
	~memory()
	{
		delete sharedPost;
	}

};

class page :public object
{
private:

	char* title;

	int totalpostsShared;
	post** timeline;

public:
	page()
	{
		title = nullptr;
		totalpostsShared = 0;
		timeline = nullptr;

		timeline = new post * [10];

		for (int i = 0; i < 10; i++)
		{
			timeline[i] = nullptr;
		}
	}

	~page()
	{

		if (title != 0)
			delete[]title;

		for (int i = 0; i < totalpostsShared; i++)
			delete timeline[i];

		delete[]timeline;
	}

	void readpagesfromfile(ifstream& fin)
	{
		char tempbuffer[50] = { '\0' };

		fin >> tempbuffer;
		SetId(tempbuffer);
		fin.getline(tempbuffer, 50);
		title = helper::getstringfrombuffer(tempbuffer);
	}
	void SharedPostIncrement() { totalpostsShared++; }
	void SetPost(post*& newpost)
	{
		if (totalpostsShared <= 10)
		{
			for (int i = 0; i < 10; i++)
			{
				if (timeline[i] == NULL)		//if index is not previously used it will poit it to the desired object
				{
					timeline[i] = newpost;
					break;
				}
			}
		}
		else
			cout << "\nMaximum Posts Have Been Liked\n";
	}
	void ShowTimeline()
	{
		cout << title << endl << endl;
		int i = 0;
		while (timeline[i] != nullptr)
		{
			timeline[i]->ViewPost();
			i++;
			cout << endl;
		}
	}

	void PrintName() { cout << GetID() << " -" << title; }
	void PrintNameOnly() { cout << title; }
	void ShowCurrentPost()
	{
		date currentdate = date::GetCurrentDate();
		date previousdate(currentdate.GetDay() - 1, currentdate.GetMonth(), currentdate.GetYear());
		for (int i = 0; i < 10; i++)
		{
			if (timeline[i] == nullptr)
				break;

			else if (timeline[i]->GetPostdate() == previousdate || timeline[i]->GetPostdate() == currentdate)
			{
				timeline[i]->ViewPost();
				cout << endl;
			}
		}
	}
};

class user : public object
{
private:

	char* fname;
	char* lname;

	int totalFriendsAdded;
	int totalPagesLiked;
	int totalpostsShared;

	user** friendlist;
	page** likedPages;
	post** timeline;
public:
	user()
	{
		fname = 0;
		lname = 0;

		totalFriendsAdded = 0;
		totalPagesLiked = 0;
		totalpostsShared = 0;

		friendlist = nullptr;
		likedPages = nullptr;

		timeline = new post * [10];

		for (int i = 0; i < 10; i++)
		{
			timeline[i] = nullptr;
		}

	}
	~user()
	{
		if (fname != 0)
			delete[]fname;

		if (lname != 0)
			delete[]lname;

		if (friendlist != 0)
			delete[]friendlist;

		if (likedPages != 0)
			delete[]likedPages;

		for (int i = 0; i < totalpostsShared; i++)
			if (timeline[i] != nullptr)
				delete timeline[i];

		delete[]timeline;
	}
	void readuserfromfile(ifstream& fin)
	{
		char tempbuffer[50] = { '\0' };

		fin >> tempbuffer;
		SetId(tempbuffer);

		fin >> tempbuffer;
		fname = helper::getstringfrombuffer(tempbuffer);

		fin >> tempbuffer;
		lname = helper::getstringfrombuffer(tempbuffer);
	}
	void SetTtotalFriends(int t) { totalFriendsAdded = t; }
	void likedPageIncrement() { totalPagesLiked++; }
	void SharedPostIncrement() { totalpostsShared++; }
	int GetTtotalFriends() { return totalFriendsAdded; }
	int GetTtotalPages() { return totalPagesLiked; }
	void LikePage(page*& newPage)
	{
		if (likedPages == 0)
		{
			likedPages = new page * [10];
			for (int i = 0; i < 10; i++)
			{
				likedPages[i] = 0;
			}
		}
		if (totalPagesLiked <= 10)
		{
			for (int i = 0; i < totalPagesLiked; i++)
			{
				if (likedPages[i] == NULL)
				{
					likedPages[i] = newPage;
					break;
				}
			}
		}
		else
			cout << "\nMaximum Pages Have Been Liked\n";
	}
	void AddFriend(user*& newFriend)
	{

		if (friendlist == 0)
		{
			friendlist = new user * [10];

			for (int i = 0; i < 10; i++)
			{
				friendlist[i] = 0;
			}
		}

		if (totalFriendsAdded <= 10)
		{
			for (int i = 0; i < totalFriendsAdded; i++)
			{
				if (friendlist[i] == NULL)
				{
					friendlist[i] = newFriend;
					break;
				}
			}
		}
		else
			cout << "\nMaximum Pages Have Been Liked\n";


	}
	void SetPost(post*& newpost)
	{
		if (totalpostsShared <= 10)
		{
			for (int i = 0; i < 10; i++)
			{
				if (timeline[i] == NULL)
				{
					timeline[i] = newpost;
					break;
				}
			}
		}
		else
			cout << "\nMaximum Posts Have Been Shared\n";

	}
	void PrintName() { cout << GetID() << " - " << fname << " " << lname; }
	void PrintNameOnly() { cout << fname << " " << lname; }
	void ViewFriendList()
	{
		this->PrintNameOnly();
		cout << " -- Friend List" << endl << endl;

		if (friendlist != 0)
		{
			int i = 0;
			while (friendlist[i] != nullptr)
			{
				friendlist[i]->PrintName();
				cout << endl;
				i++;
			}
		}
		else
		{
			helper::ShowLine();
		}
	}
	void ShowLikedPages()
	{

		this->PrintNameOnly();
		cout << " -- Like Pages" << endl << endl;

		for (int i = 0; i < totalPagesLiked; i++)
		{
			likedPages[i]->PrintName();
			cout << endl;
		}
		helper::ShowLine();

	}
	void ShowTimeline()
	{
		cout << fname << " " << lname << " -TimeLine" << endl << endl;

		int i = 0;
		while (timeline[i] != nullptr)
		{
			timeline[i]->ViewPost();
			i++;
			cout << endl;
		}
	}
	void ViewHome()
	{
		PrintNameOnly();
		cout << " -Home Page\n" << endl;

		date currentdate = date::GetCurrentDate();
		date previousdate(currentdate.GetDay() - 1, currentdate.GetMonth(), currentdate.GetYear());
		for (int i = 0; i < 10; i++)
		{
			if (friendlist[i] == nullptr)
				break;
			else
			{
				for (int j = 0; j < 10; j++)
				{

					if (friendlist[i]->timeline[j] == nullptr)
						break;
					else
					{
						if (friendlist[i]->timeline[j]->GetPostdate() == currentdate || friendlist[i]->timeline[j]->GetPostdate() == previousdate)
						{
							friendlist[i]->timeline[j]->ViewPost();
							cout << endl;
						}
					}
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (likedPages[i] == nullptr)
				break;
			else
				likedPages[i]->ShowCurrentPost();
		}

	}
	void SeeYourMemory()
	{
		date current = date::GetCurrentDate();
		for (int i = 0; i < 10; i++)
		{
			if (timeline[i] != nullptr)
			{
				date postdate = timeline[i]->GetPostdate();
				if (current.GetDay() == postdate.GetDay() && current.GetMonth() == postdate.GetMonth() && current.GetYear() > postdate.GetYear())
				{
					cout << endl << "We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago." << endl << endl;
					cout << "On this Day" << endl;
					cout << current.GetYear() - postdate.GetYear() << " years ago" << endl;

					timeline[i]->ViewPost();
				}
			}
		}

	}
};
class facebook
{
private:
	int totalpages;
	int totalusers;
	int totalposts;
	int totalcomments;
	user** allUsers;
	page** allPages;
	post** allPosts;

public:
	facebook()
	{
		totalpages = 0;
		totalusers = 0;
		totalposts = 0;
		totalcomments = 0;

		allUsers = nullptr;
		allPages = nullptr;
		allPosts = nullptr;

	}
	~facebook()
	{
		Deallocate(allPages, totalpages);
		Deallocate(allUsers, totalusers);
		delete[]allPosts;

	}
	void loaddata(const char* pagesfile, const char* userfile, const char* postfile, const char* commentfile)
	{
		loadpages(pagesfile);
		loadusers(userfile);
		loadposts(postfile);
		loadcomments(commentfile);
	}
	void loadpages(const char* filename)
	{
		ifstream inpage(filename);
		if (inpage.is_open())
		{
			int totalPagesAdded = 0;
			inpage >> totalpages;

			allPages = new page * [totalpages];

			for (int i = 0; i < totalpages; i++)
			{
				allPages[i] = new page;
				allPages[i]->readpagesfromfile(inpage);
			}
			inpage.close();
		}
		else
			cout << "ERROR IN FILE OPENING\n";
	}
	void loadusers(const char* filename)
	{
		ifstream inUser(filename);
		if (inUser.is_open())
		{
			inUser >> totalusers;

			allUsers = new user * [totalusers];

			char*** tempfriendlist = new char** [totalusers];
			for (int i = 0; i < totalusers; i++)
			{
				allUsers[i] = new user;
				allUsers[i]->readuserfromfile(inUser);

				tempfriendlist[i] = new char* [10];

				char buffer[20]{};
				int j = 0;
				while (buffer[0] != '-')	//reading added friends and storing in temporary array
				{
					//storing added friend temporarily before association
					inUser >> buffer;
					tempfriendlist[i][j++] = helper::getstringfrombuffer(buffer);
				}
				allUsers[i]->SetTtotalFriends(j);

				char tempbuffer[20]{};
				while (tempbuffer[0] != '-')	//reading liked pages and associating with the user
				{
					inUser >> tempbuffer;
					char* idcheck = helper::getstringfrombuffer(tempbuffer);
					if (tempbuffer[0] != '-')
					{
						page* pagePTR = SearchPageByID(idcheck);
						allUsers[i]->likedPageIncrement();			//everytime we read a page +1 in totallikedpages
						allUsers[i]->LikePage(pagePTR);
					}
				}


			}inUser.close();

			for (int i = 0; i < totalusers; i++)
			{
				for (int j = 0; j < allUsers[i]->GetTtotalFriends(); j++)
				{
					user* userptr = SearchUserByID(tempfriendlist[i][j]);
					allUsers[i]->AddFriend(userptr);
				}
			}
			DeallocatetempFL(tempfriendlist, totalusers);


		}
		else
			cout << "ERROR IN FILE OPENING\n";

	}	void loadposts(const char* filename)
	{
		ifstream inPost(filename);

		if (inPost.is_open())
		{
			inPost >> totalposts;
			allPosts = new  post * [totalposts];

			for (int i = 0; i < totalposts; i++)
			{
				allPosts[i] = new post;
				allPosts[i]->ReadPostFromFile(inPost);

				char buffer[50] = { '\0' };

				inPost >> buffer;				//reading id of person/page who shared post

				object* ptr = SearchObjectByID(buffer);
				allPosts[i]->SetSharedBy(ptr);
				ptr->SetPost(allPosts[i]);

				char likerbuffer[50] = { '\0' };
				//reading likers
				while (likerbuffer[0] != '-')
				{
					inPost >> likerbuffer;

					object* likerptr = SearchObjectByID(likerbuffer);
					allPosts[i]->likeIncrement();
					allPosts[i]->SetLikedBy(likerptr);

				}
			}
			inPost.close();
		}
		else
			cout << "ERROR IN FILE OPENING :: posts file\n";
	}
	void loadcomments(const char* filename)
	{
		ifstream inComment(filename);

		if (inComment.is_open())
		{
			inComment >> totalcomments;
			char buffer[100] = { '\0' };
			char buffer2[30] = { '\0' };

			for (int i = 0; i < totalcomments; i++)
			{
				comment* commentptr = new comment;

				inComment >> buffer;
				commentptr->SetId(helper::getstringfrombuffer(buffer));

				inComment >> buffer;
				post* ptr = SearchPostByID(helper::getstringfrombuffer(buffer));

				ptr->SetComments(commentptr);

				ptr->CommentIncrement();


				inComment >> buffer2;

				object* commentbyPTR = SearchObjectByID(helper::getstringfrombuffer(buffer2));
				commentptr->SetCommentBy(commentbyPTR);

				inComment.getline(buffer, 100);

				commentptr->SetText(helper::getstringfrombuffer(buffer));
			}
		}
		else
			cout << "\nError in opening comments file\n";
	}

	user* SearchUserByID(char* id)
	{
		for (int i = 0; i < totalusers; i++)
		{
			if (helper::CompareString(allUsers[i]->GetID(), id))
			{
				return allUsers[i];				//retuning the object with req ID
			}
		}
		return NULL;			//if id not found
	}
	page* SearchPageByID(char* id)
	{
		for (int i = 0; i < totalusers; i++)
		{
			if (helper::CompareString(allPages[i]->GetID(), id))
			{
				return allPages[i];				//retuning the object with req ID
			}
		}
		return NULL;			//if id not found
	}
	post* SearchPostByID(char* id)
	{

		for (int i = 0; i < totalposts; i++)
		{
			if (helper::CompareString(allPosts[i]->GetID(), id))
			{
				return allPosts[i];				//retuning the object with req ID
			}
		}
		return NULL;			//if id not found
	}
	object* SearchObjectByID(char* id)
	{
		if (id[0] == 'u')
		{
			object* userptr = SearchUserByID(helper::getstringfrombuffer(id));
			return userptr;
		}
		else if (id[0] == 'p')
		{
			object* pageptr = SearchPageByID(helper::getstringfrombuffer(id));
			return pageptr;
		}
		else
			return nullptr;
	}

	void DeallocatetempFL(char*** tempList, int n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < allUsers[i]->GetTtotalFriends(); j++)
			{
				delete[]tempList[i][j];
				tempList[i][j] = 0;
			}

		}
		delete[] tempList;
		tempList = 0;
	}
	void SetCurrentdate(int d, int m, int y)
	{
		date::SetCurrentDate(d, m, y);
		cout << "System Date set to :";
		date::GetCurrentDate().PrintDate();
	}

	void ShowLikedList(char* postid)
	{
		post* currentpost = 0;
		currentpost = SearchPostByID(postid);
		helper::ShowLine();

		if (currentpost != nullptr)
			currentpost->ViewLikedList();
		else
			cout << "\nPost Not Available" << endl;
	}
	void CommentIncrement() { totalcomments++; }
	void PostComment(char* commenttext, user* userptr, post* postcommentptr)
	{
		//cout << "command:\tpostcomment(" << postcommentptr->GetID() << ", " << commenttext << ")" << endl;
		//helper::ShowLine();
		facebook::CommentIncrement();

		comment* commentptr = new comment;
		char tempid[4] = "c";
		commentptr->SetId(helper::Concatenate(tempid, helper::int_to_char(totalcomments)));
		commentptr->SetText(commenttext);
		commentptr->SetCommentBy(userptr);

		postcommentptr->AddComment(commentptr);

		delete commentptr;
		cout << endl;
	}

	void Run()
	{
		const int day = 15, month = 11, year = 2017;
		cout << "Command :\tSet Current Date To : " << day << " " << month << " " << year << endl;

		SetCurrentdate(day, month, year);

		char User1[] = "u7";
		cout << "\nCommand :\tSet Current User To : " << User1 << endl;

		user* currentUser = 0;
		currentUser = SearchUserByID(User1);
		if (currentUser != 0)
		{
			currentUser->PrintNameOnly();
			cout << " successfully set as CurrentUser" << endl << endl;

			helper::ShowLine();
			cout << "Command :\tViewFriendList" << endl;
			
			helper::ShowLine();
			
			currentUser->ViewFriendList();
			helper::ShowLine();

			cout << "Command :\tViewLikedPages " << endl;
			helper::ShowLine();
			currentUser->ShowLikedPages();


			cout << "Command : \tView Home" << endl;
			helper::ShowLine();
			currentUser->ViewHome();
			helper::ShowLine();


			cout << "Command : ViewTimeLine" << endl;
			helper::ShowLine();
			currentUser->ShowTimeline();


			char Post[] = "post5";
			post* currentpost = 0;
			currentpost = SearchPostByID(Post);
			helper::ShowLine();

			if (currentpost != 0)
			{
				cout << "command:\tviewlikedlist(post5)\n";
				helper::ShowLine();
				currentpost->ViewLikedList();
				helper::ShowLine();

				cout << "command:\tlikepost(" << Post << ")" << endl;
				cout << "command:\tviewlikedlist(post5)\n";
				helper::ShowLine();

				object* CurrentUserr = currentUser;
				currentpost->SetLikedBy(CurrentUserr);
				currentpost->ViewLikedList();

			}
			else
				cout << "\nPost Not Available" << endl;



			char postid[] = "post4";
			char addcomment[] = "Good Luck For Your Result";
			helper::ShowLine();

			post* postcommentptr = SearchPostByID(postid);

			if (postcommentptr != 0)
			{
				cout << "command:\tpostcomment(" << postcommentptr->GetID() << ", " << addcomment << ")" << endl;
				cout << "Command : \tView Post" << endl;

				helper::ShowLine();

				PostComment(addcomment, currentUser, postcommentptr);
				postcommentptr->ViewPost();
			}
			else
				cout << "\nComment Not Available" << endl;




			char postid1[] = "post8";
			char addcomment1[] = "Thanks for the wishes.";
			helper::ShowLine();

			post* postcommentptr1 = SearchPostByID(postid1);
			if (postcommentptr1 != 0)
			{
				cout << "command:\tpostcomment(" << postcommentptr1->GetID() << ", " << addcomment1 << ")" << endl;
				cout << "Command : \tView Post" << endl;
				
				helper::ShowLine();

				PostComment(addcomment1, currentUser, postcommentptr1);
				postcommentptr1->ViewPost();

			}
			else
				cout << "\nComment Not Available" << endl;

			helper::ShowLine();

			cout << "Command : \tSee Your Memory" << endl;
			helper::ShowLine();

			currentUser->SeeYourMemory();
		}
		else
			cout << "\nUser Not Found\n";

		helper::ShowLine();

		char Page[] = "p1";
		cout << "command:\tviewpage(" << Page << ")" << endl;
		
		helper::ShowLine();

		page* currentpage = 0;
		currentpage = SearchPageByID(Page);

		if (currentpage != 0)
			currentpage->ShowTimeline();
		else
			cout << "\nPage Not Found\n";
		helper::ShowLine();


		helper::ShowLine();
		char User2[] = "u11";
		cout << "\nCommand :\tSet Current User To : " << User2 << endl;

		user* currentUser2 = 0;
		currentUser2 = SearchUserByID(User2);
		if (currentUser2 != 0)
		{
			currentUser2->PrintNameOnly();
			cout << " successfully set as CurrentUser\n"  << endl;
			helper::ShowLine();

			cout << "Command : ViewTimeLine" << endl;
			helper::ShowLine();
			currentUser2->ShowTimeline();
			helper::ShowLine();

			cout << "Command : \tView Home\n";
			helper::ShowLine();
			currentUser2->ViewHome();
			
			helper::ShowLine();

		}
		else
			cout << User2 << " not founr" << endl;

	}

};

int main()
{
	facebook app;

	app.loaddata("Project-SocialNetworkPages.txt", "Project-SocialNetworkUsers.txt", "Project-SocialNetworkPosts.txt", "Project-SocialNetworkComments.txt");
	
	app.Run();
}