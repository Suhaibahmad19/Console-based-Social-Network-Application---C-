Console-based Social Network Application




Project Description
We need to develop a console based social network application. 

Each User in the application has a unique ID and name. He may have other users in his friend list, having 10 friends at max. He has a list of pages which he has liked (10 likedpages at max). 

Each Page has a unique ID, title, list of posts it has shared (page’s timeline) and total number of people who have liked it. 

Each Post has a unique ID, description/text, no of likes, list of people who have liked it and shared date for example; a post is shared at 25th October 2017. A post can have 10 comments at max. 

Activity may be a part of the Post, having a type and a value against this type. See table below for details:
	Type					Value
1 	feeling   			Happy/sad/excited etc.
2	thinking about	    life/future/meaning of life etc.
3	Making      		Money/art/memories etc.
4	celebrating	A 		birthday/Halloween/success etc.

Our application doesn’t support types Eating, Travelling, Drinking, and Watching etc. at the moment.

A Memory is a Post having pointer to original post.
A comment is posted by a specific user or page. All the Users, Pages and Posts in the application are Objects having IDs.
 
Required Functionality:
Set Current User
	Ask user about his ID and set him as current user of application. Now everything that we see in the system will be view of this user.
View Home of Current User
	Display posts of all friends shared in last 24 hours.
	Display posts of all his liked pages shared in last 24 hours. 
Like a post
	Ask user about ID of post and like it. A post can be liked by 10 users at max.
View the list of People who liked a post
	Take Post ID from user and display list of people who have liked it
Comment on a Post
	Take post ID and comment from the user and add this comment in the post
View a Post
	Take post ID and Display the post with its Comments

View User’s Timeline
	Display User Name
	Display user’s posts in his timeline
View Friend List
	Take ID of a user and display his friends list
View Page
	Take Page ID and display all its posts

Important Instructions

You are not allowed to use global variables and functions
Use best practices studied so far
Memory deallocation carries significant weightage
All the arrays should be dynamically allocated.
Wherever you need an array of objects, keep it as double pointer. If a page has no posts or if a user has no friends and no liked pages then these double pointers should be null.
Sample Run: You are required to bring following output (on your console window) at time of your evaluation. DO NOT ASK USER TO ENTER ANYTHING AT RUNTIME. (Make a function SocialNetworkApp::Run() and hardcode function calls to run following sample).

Phase I includes output "View Friend List" & "View Liked Pages". U7 is just a sample, your program should properly run on any user.

Command:                Set current System Date 15 11 2017
System Date:            15/11/2017

Command:                Set current user “u7”
Abdullah Nadeem successfully set as Current User


Command:                View Friend List
-------------------------------------------------------------------------------------------------------------
Abdullah Nadeem – Friend List

u3 - Waheed Khan
u11 – Ahsan Ali
u12 – Ali Ahmed
---------------------------------------------------------------------------------------------------------------

Comand:                  View Liked Pages
---------------------------------------------------------------------------------------------------------------
Abdullah Nadeem – Liked Pages


P1 – Food Fusion
P2 – Al Jazeera English
P5 – Rumi Quotes
P9 – BBC News
---------------------------------------------------------------------------------------------------------------
Command:                View Home
---------------------------------------------------------------------------------------------------------------
Abdullah Nadeem – Home Page 

//This is displaying posts of 15th and 14th November (15th Nov is currentDate)

--- Waheed Khan is feeling excited
     “OOP Project Started Yayy...”
                                        Amna Akram wrote: “Best of Luck”
                                        Abdullah Nadeem wrote: “Interesting”

--- Ahsan Ali shared “Waiting for Weekend”
                                        Saad Ali wrote: “Any plans for Get Together?”
                                        Abdullah Nadeem wrote: “Yes BBQ”
                                        Nimra Batool wrote: “Lunch Buffet please”

--- Ali Ahmed shared “Waiting for Result”

--- Food Fusion is making Kashmiri Chai (Pink Tea).
     “Try this at home...”
                                        Food Fusion wrote: “Followers please try this recipe and give your feedback”
                                        Amna Akram wrote: “Yummy”
                                        Ahsan Ali wrote: “One pink tea for me”

--- Al Jazeera English shared “Oil drilling in Alaska's indigenous communities is on the table again.”

--- Rumi Quotes shared “Be free of possessing things - Rumi”
                                        Ali Ahmed wrote: “Rumi is great”

//Notice the format of printing Activity and Simple Posts
---------------------------------------------------------------------------------------------------------------
Command:                  View TimeLine
---------------------------------------------------------------------------------------------------------------
Abdullah Nadeem –Time Line

--- Abdullah Nadeem is Celebrating a birthday
     “Happy Birthday to my dear Mom” … (14/11/2017)
                                        Waheed Khan wrote: “Happy Birthday Aunty”

--- Abdullah Nadeem is Celebrating a birthday
     “Happy Birthday to my dear Father” … (14/10/2017)
                                        Ahsan Ali wrote: “Happy Birthday Uncle”

--- Abdullah Nadeem is Celebrating Success
     “Got D in toughest subject… Thanks God I am Pass finally…” … (15/11/2015)
                                        Ahsan Ali wrote: “Celebrations???”

---------------------------------------------------------------------------------------------------------------
Command:                   ViewLikedList(post5)

Post Liked By:
U2 – Amna Akram
P1 – Food Fusion
U3 - Waheed Khan
U4 - Burhan Tahir
---------------------------------------------------------------------------------------------------------------
Command:                   LikePost(post5)
Command:                   ViewLikedList(post5)

Post Liked By:
U2 – Amna Akram
P1 – Food Fusion
U3 - Waheed Khan
U4 - Burhan Tahir
u7 – Abdullah Nadeem
---------------------------------------------------------------------------------------------------------------
Command:                   PostComment(post4, Good Luck for your Result)
Command:                   ViewPost(post4)

--- Ali Ahmed shared “Waiting for Result”
                                        Abdullah Nadeem wrote: “Good Luck for your Result”
---------------------------------------------------------------------------------------------------------------
Command:                   PostComment(post8, Thanks for the wishes)
Command:                   ViewPost(post8)


--- Abdullah Nadeem is Celebrating a birthday
     “Happy Birthday to my dear Mom” … (14/11/2017)
                                        Waheed Khan wrote: “Happy Birthday Aunty”
                                        Abdullah Nadeem wrote: “Thanks for the wishes”

---------------------------------------------------------------------------------------------------------------
Command:                   SeeYourMemories() //Imp: Sharing a memory multiple times??

We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago.

On this Day
2 Years Ago
--- Abdullah Nadeem is Celebrating Success
     “Got D in toughest subject… Thanks God I am Pass finally…” … (15/11/2015)
                                        Ahsan Ali wrote: “Celebrations???”
---------------------------------------------------------------------------------------------------------------
Command:                  ShareMemory(post10, “Never thought I will be specialist in this field…”)
Command:                  View TimeLine


Abdullah Nadeem –Time Line

~~~ Abdullah Nadeem shared a memory ~~~ …(15/11/2017)
“Never thought I will be specialist in this field…”
                               (2 Years Ago)
--- Abdullah Nadeem is Celebrating Success
     “Got D in toughest subject… Thanks God I am Pass finally…” … (15/11/2015)


--- Abdullah Nadeem is Celebrating a birthday
     “Happy Birthday to my dear Mom” … (14/11/2017)
                                        Waheed Khan wrote: “Happy Birthday Aunty”

--- Abdullah Nadeem is Celebrating a birthday
     “Happy Birthday to my dear Father” … (14/10/2017)
                                        Ahsan Ali wrote: “Happy Birthday Uncle”

--- Abdullah Nadeem is Celebrating Success
     “Got D in toughest subject… Thanks God I am Pass finally…” … (15/11/2015)
                                        Ahsan Ali wrote: “Celebrations???”


---------------------------------------------------------------------------------------------------------------
Command:                   ViewPage(p1)

Food Fusion
--- Food Fusion is making Kashmiri Chai (Pink Tea). … (14/11/2017)
     “Try this at home...”
                                        Food Fusion wrote: “Followrs please try this recipe and give your feedback”
                                        Amna Akram wrote: “Yummy”
                                        Ahsan Ali wrote: “One pink tea for me”

--- Food Fusion is making Halwa Puri. … (10/11/2017)
     “Sunday Special Breakfast for our followers...”

Command:                Set current user “u11”
Ahsan Ali successfully set as Current User
Command: ViewHome
Command: ViewTimeline

