using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using HtmlAgilityPack;

namespace Crawler1
{
    class Program
    {
        static void Main(string[] args)
        {
            SrtartCrowlerAsync();

            Console.ReadLine();
        }
        private static async Task SrtartCrowlerAsync()
        {
            var url = "https://www.automobile.tn/neuf/bmw.3/";

            var httpCilent = new HttpClient();
            var html = await httpCilent.GetStringAsync(url);

            var htmlDocument = new HtmlDocument();
            htmlDocument.LoadHtml(html);

            var divs = htmlDocument.DocumentNode.Descendants("div")
                 .Where(node => node.GetAttributeValue("class", "")
                 .Equals("article_new_car article_last_modele")).ToList();

            var cars = new List<Car>();

            foreach (var div in divs)
            {
            

                var car = new Car
                {
                 Model = div?.Descendants("h2")?.FirstOrDefault()?.InnerText,
                 Price= div?.Descendants("div")?.FirstOrDefault()?.InnerText,
                 ImageUrl = div?.Descendants("img")?.FirstOrDefault()?.ChildAttributes("src")?.FirstOrDefault()?.Value,
                 Link = div?.Descendants("a")?.FirstOrDefault()?.ChildAttributes("href")?.FirstOrDefault()?.Value
                };
                cars.Add(car);
            }
        }
    }
    
    public class Car
    {
        public string Model { get; set; }
        public string Price { get; set; }
        public string ImageUrl { get; set; }
        public string Link { get; set; }
    }
}
