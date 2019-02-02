using System;
using System.Xml;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using HtmlAgilityPack;
using Newtonsoft.Json;

namespace WebCrawler_20190201
{
    class Program
    {
        static void Main(string[] args)
        {
            StartAgilityPack();
            Console.ReadLine();
        }

        private static void StartAgilityPack()
        {
            Hike info = new Hike();

            var html = @"http://www.thma.org.tw/event.php";

            HtmlWeb web = new HtmlWeb();

            var htmlDoc = web.Load(html);

            var tr = htmlDoc.DocumentNode.Descendants("tr")
                .Where(node => node.GetAttributeValue("valign", "")
                .Equals("top")).ToList(); ;

            foreach (var Event in tr)
            {
                info.ID = Event?.Descendants("a")?.FirstOrDefault()?.InnerText;

                info.NAME = Event?.Descendants("td")?.Where(node =>/*lambda expression*/ node.GetAttributeValue("style", "")
                  .Equals("text-align:left;")).First().InnerText;

                info.LV = Event?.Descendants("td")?.ElementAt(2)?.InnerText;

                info.START = Event?.Descendants("td")?.ElementAt(3)?.InnerText;

                info.END = Event?.Descendants("td")?.ElementAt(4)?.InnerText;

                info.GUIDE = Event?.Descendants("td")?.ElementAt(5)?.InnerText;
                info.GUIDE = info.GUIDE.Replace("\r", ",").Replace("\t", "").Replace("\n", "").Replace(" ", "");

                info.CONTENTS = Event?.Descendants("td")?.Last()?.InnerText;

                var output = JsonConvert.SerializeObject(info);
                /*using JsonConvert to output Json type. */
                Console.WriteLine(output);

            }
        }
    }
    public class Hike
    {
        public string ID{ get; set; }
        public string NAME { get; set; }
        public string LV { get; set; }
        public string START { get; set; }
        public string END { get; set; }
        public string GUIDE { get; set; }
        public string CONTENTS { get; set; }
    }

}

/*References:
 Lambda Expression(委派之用法): https://docs.microsoft.com/zh-tw/dotnet/csharp/programming-guide/statements-expressions-operators/lambda-expressions
 Linq: https://docs.microsoft.com/zh-tw/dotnet/csharp/programming-guide/concepts/linq/getting-started-with-linq
 HtmlAgilityPack: https://dotnetfiddle.net/Vtwi7g
 JsonType: https://www.newtonsoft.com/json/help/html/M_Newtonsoft_Json_JsonConvert_SerializeObject_5.htm
    */
/*Questions
 1. 是否可以查找內文資訊時用from where select 再跑foreaach，以增加可讀性?
 2. 為何public class已經是Public了，string仍要設為public?
 3. 為何在class hike中要使用get;set;?
     */
