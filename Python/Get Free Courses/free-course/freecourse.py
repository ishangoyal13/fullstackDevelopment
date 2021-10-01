import requests
from bs4 import BeautifulSoup

'''
Scrapes  Free Courses Detail from Disudemy 
'''
baseurl = "https://www.discudemy.com/search/"


def req(url):
    respponse = requests.get(url).text
    return respponse


class Courses:
    def __init__(self, topic) -> None:
        self.topic = topic
        content = req((baseurl + self.topic))
        html_content = BeautifulSoup(content, "html.parser")
        self.content_in_div = html_content.find("div", "content")

    def get_course_title(self):
        course_title = (self.content_in_div.find("a", "card-header")).text
        return course_title

    def get_course_desc(self):
        course_description = (self.content_in_div.find("div", "description")).text
        return course_description

    def get_course_thumbnail(self):
        image_link = (self.content_in_div.find("amp-img"))["src"]
        return image_link

    def get_courselink(self):
        disudemy_course_link = (self.content_in_div.find("a", "card-header"))["href"]
        disudemy_takecourse_button = req(disudemy_course_link)
        disudemy_couponlink = (BeautifulSoup(disudemy_takecourse_button, "html.parser")).find("div", "ui center aligned basic segment")
        downloadpagelink = (disudemy_couponlink.find("a"))["href"]
        lastpage = req(downloadpagelink)
        link = (
            BeautifulSoup(lastpage, "html.parser")
            .find("div", "ui segment")
            .find("a")["href"]
        )
        return link


if __name__ == "__main__":
    topic = input("Input Topic or Course name: ")
    course = Courses(topic=topic)
    print(course.get_course_title())
    print(course.get_course_desc().strip())
    print(course.get_course_thumbnail())
    print(course.get_courselink())
