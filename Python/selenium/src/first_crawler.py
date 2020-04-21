#!/usr/bin/python
#coding:utf-8

from selenium import webdriver
import time

driver = webdriver.Chrome(executable_path="chromedriver")

driver.set_window_size("1200", "800")
driver.implicitly_wait(10)

url = "https://google.com.tw"
driver.get(url)
elem = driver.find_element_by_xpath("//input[@name='q']")
elem.send_keys('天氣')
time.sleep(3)
click = driver.find_element_by_class_name('gNO89b')
click.click()
time.sleep(3)
driver.quit()