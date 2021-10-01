
# Get Free Course

### Using this Python-programmed program, you can search for free courses on Udemy

## Run

```bash
  git clone <repo url>
  cd free-course
  pip3 install -r requirements.txt
  python3 freecourse.py
```

## Some Methods available

```course = Courses(topic="python")
course.get_course_title() # returns course get_course_title
course.get_course_desc()  # returns course Description 
course.get_course_thumbnail() # returns Thumbnail image direct link
course.get_course_link() # returns direct udemy link to free course 
```
