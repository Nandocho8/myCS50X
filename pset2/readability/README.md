<h1>Readability</h1>

<p>For this problem, you’ll implement a program that calculates the approximate grade level needed to comprehend some text, per the below.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
</code></pre></div></div>

<h2>Background</h2>

<p>According to <a href="https://www.scholastic.com/teachers/teaching-tools/collections/guided-reading-book-lists-for-every-level.html">Scholastic</a>, E.B. White’s <em>Charlotte’s Web</em> is between a second- and fourth-grade reading level, and Lois Lowry’s <em>The Giver</em> is between an eighth- and twelfth-grade reading level. What does it mean, though, for a book to be at a particular reading level?</p>

<p>Well, in many cases, a human expert might read a book and make a decision on the grade (i.e., year in school) for which they think the book is most appropriate. But an algorithm could likely figure that out too!</p>

<p>So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels. Likewise, longer sentences probably correlate with higher reading levels, too.</p>

<p>A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text. One such readability test is the <em>Coleman-Liau index</em>. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>index = 0.0588 * L - 0.296 * S - 15.8
</code></pre></div></div>

<p>where <code class="language-plaintext highlighter-rouge">L</code> is the average number of letters per 100 words in the text, and <code class="language-plaintext highlighter-rouge">S</code> is the average number of sentences per 100 words in the text.</p>

<p>Let’s write a program called <code class="language-plaintext highlighter-rouge">readability</code> that takes a text and determines its reading level. For example, if user types in a line of text from Dr. Seuss, the program should behave as follows:</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
</code></pre></div></div>

<p>The text the user inputted has 65 letters, 4 sentences, and 14 words. 65 letters per 14 words is an average of about 464.29 letters per 100 words (because 65 / 14 * 100 = 464.29). And 4 sentences per 14 words is an average of about 28.57 sentences per 100 words (because 4 / 14 * 100 = 28.57). Plugged into the Coleman-Liau formula, and rounded to the nearest integer, we get an answer of 3 (because 0.0588 * 464.29  - 0.296 * 28.57 - 15.8 = 3): so this passage is at a third-grade reading level.</p>

<p>Let’s try another one:</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./readability
Text: Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.
Grade 5
</code></pre></div></div>

<p>This text has 214 letters, 4 sentences, and 56 words. That comes out to about 382.14 letters per 100 words, and 7.14 sentences per 100 words. Plugged into the Coleman-Liau formula, we get a fifth-grade reading level.</p>

<p>As the average number of letters and words per sentence increases, the Coleman-Liau index gives the text a higher reading level. If you were to take this paragraph, for instance, which has longer words and sentences than either of the prior two examples, the formula would give the text an twelfth-grade reading level.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./readability
Text: As the average number of letters and words per sentence increases, the Coleman-Liau index gives the text a higher reading level. If you were to take this paragraph, for instance, which has longer words and sentences than either of the prior two examples, the formula would give the text an twelfth-grade reading level.
Grade 12
</code></pre></div></div>



<h2>Specification</h2>

<p>Design and implement a program, <code class="language-plaintext highlighter-rouge">readability</code>, that computes the Coleman-Liau index of text.</p>

<ul class="fa-ul">
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>Implement your program in a file called <code class="language-plaintext highlighter-rouge">readability.c</code> in a directory called <code class="language-plaintext highlighter-rouge">readability</code>.</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>Your program must prompt the user for a <code class="language-plaintext highlighter-rouge">string</code> of text using <code class="language-plaintext highlighter-rouge">get_string</code>.</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from <code class="language-plaintext highlighter-rouge">a</code> to <code class="language-plaintext highlighter-rouge">z</code> or any uppercase character from <code class="language-plaintext highlighter-rouge">A</code> to <code class="language-plaintext highlighter-rouge">Z</code>, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>Your program should print as output <code class="language-plaintext highlighter-rouge">"Grade X"</code> where <code class="language-plaintext highlighter-rouge">X</code> is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output <code class="language-plaintext highlighter-rouge">"Grade 16+"</code> instead of giving the exact index number. If the index number is less than 1, your program should output <code class="language-plaintext highlighter-rouge">"Before Grade 1"</code>.</li>
</ul>

<h3>Getting User Input</h3>

<p>Let’s first write some C code that just gets some text input from the user, and prints it back out. Specifically, implement in <code class="language-plaintext highlighter-rouge">readability.c</code> a <code class="language-plaintext highlighter-rouge">main</code> function that prompts the user with <code class="language-plaintext highlighter-rouge">"Text: "</code> using <code class="language-plaintext highlighter-rouge">get_string</code> and then prints that same text using <code class="language-plaintext highlighter-rouge">printf</code>. Be sure to <code class="language-plaintext highlighter-rouge">#include</code> any necessary header files.</p>

<p>The program should behave per the below.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./readability
Text: In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.
In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.
</code></pre></div></div>

<h3>Letters</h3>

<p>Now that you’ve collected input from the user, let’s begin to analyze that input by first counting the number of letters in the text. Consider letters to be uppercase or lowercase alphabetical character, not punctuation, digits, or other symbols.</p>

<p>Add to <code class="language-plaintext highlighter-rouge">readability.c</code>, below <code class="language-plaintext highlighter-rouge">main</code>, a function called <code class="language-plaintext highlighter-rouge">count_letters</code> that takes one argument, a <code class="language-plaintext highlighter-rouge">string</code> of text, and that returns an <code class="language-plaintext highlighter-rouge">int</code>, the number of letters in that text. Be sure to add the function’s prototype, too, atop your file, so that <code class="language-plaintext highlighter-rouge">main</code> knows how to call it. Odds are the prototype should resemble the below:</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="kt">int</span> <span class="n">count_letters</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">)</span>
</code></pre></div></div>

<p>Then call that function in <code class="language-plaintext highlighter-rouge">main</code> so that, instead of printing out the text itself, your program now prints the number of letters in the text.</p>

<p>The program should now behave per the below.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./readability
Text: Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, "and what is the use of a book," thought Alice "without pictures or conversation?"
235 letters
</code></pre></div></div>

<details><summary>Hint</summary><p>Declared in <code class="language-plaintext highlighter-rouge">ctype.h</code> is a function that you might find helpful, per <a href="https://manual.cs50.io/">manual.cs50.io</a>. If you use it, be sure to include that header file atop your own code!</p></details>

<h3>Words</h3>

<p>The Coleman-Liau index cares not only about the number of letters but also about the number of words in a sentence. For the purpose of this problem, we’ll consider any sequence of characters separated by a space to be a word (so a hyphenated word like <code class="language-plaintext highlighter-rouge">"sister-in-law"</code> should be considered one word, not three).</p>

<p>Add to <code class="language-plaintext highlighter-rouge">readability.c</code>, below <code class="language-plaintext highlighter-rouge">main</code>, a function called <code class="language-plaintext highlighter-rouge">count_words</code> that takes one argument, a <code class="language-plaintext highlighter-rouge">string</code> of text, and that returns an <code class="language-plaintext highlighter-rouge">int</code>, the number of words in that text. Be sure to add the function’s prototype, too, atop your file, so that <code class="language-plaintext highlighter-rouge">main</code> knows how to call it. (We leave its prototype to you!)</p>

<p>Then call that function in <code class="language-plaintext highlighter-rouge">main</code> so that your program also prints the number of words in the text.</p>

<p>You may assume that a sentence:</p>
<ul class="fa-ul">
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>will contain at least one word;</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>will not start or end with a space; and</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>will not have multiple spaces in a row.</li>
</ul>

<p>You are, of course, welcome to attempt a solution that will tolerate multiple spaces between words or indeed, no words!</p>

<p>The program should now behave per the below.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./readability
Text: It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.
250 letters
55 words
</code></pre></div></div>

<h3>Sentences</h3>

<p>The last piece of information that the Coleman-Liau formula cares about, in addition to the number of letters and words, is the number of sentences. Determining the number of sentences can be surprisingly trickly. You might first imagine that a sentence is just any sequence of characters that ends with a period, but of course sentences could end with an exclamation point or a question mark as well. But of course, not all periods necessarily mean the sentence is over. For instance, consider the sentence below.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>Mr. and Mrs. Dursley, of number four Privet Drive, were proud to say that they were perfectly normal, thank you very much.
</code></pre></div></div>

<p>This is just a single sentence, but there are three periods! For this problem, we’ll ask you to ignore that subtlety: you should consider any sequence of characters that ends with a <code class="language-plaintext highlighter-rouge">.</code> or a <code class="language-plaintext highlighter-rouge">!</code> or a <code class="language-plaintext highlighter-rouge">?</code> to be a sentence (so for the above “sentence”, you should count it as three sentences). In practice, sentence boundary detection needs to be a little more intelligent to handle these cases, but we’ll not worry about that for now.</p>

<p>Add to <code class="language-plaintext highlighter-rouge">readability.c</code>, below <code class="language-plaintext highlighter-rouge">main</code>, a function called <code class="language-plaintext highlighter-rouge">count_sentences</code> that takes one argument, a <code class="language-plaintext highlighter-rouge">string</code> of text, and that returns an <code class="language-plaintext highlighter-rouge">int</code>, the number of sentences in that text. Be sure to add the function’s prototype, too, atop your file, so that <code class="language-plaintext highlighter-rouge">main</code> knows how to call it. (We again leave its prototype to you!)</p>

<p>Then call that function in <code class="language-plaintext highlighter-rouge">main</code> so that your program also prints the number of sentences in the text.</p>

<p>The program should now behave per the below.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./readability
Text: When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.
295 letters
70 words
3 sentences
</code></pre></div></div>

<h3>Putting it All Together</h3>

<p>Now it’s time to put all the pieces together! Recall that the Coleman-Liau index is computed using the formula:</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>index = 0.0588 * L - 0.296 * S - 15.8
</code></pre></div></div>

<p>where <code class="language-plaintext highlighter-rouge">L</code> is the average number of letters per 100 words in the text, and <code class="language-plaintext highlighter-rouge">S</code> is the average number of sentences per 100 words in the text.</p>

<p>Modify <code class="language-plaintext highlighter-rouge">main</code> in <code class="language-plaintext highlighter-rouge">readability.c</code> so that instead of outputting the number of letters, words, and sentences, it instead outputs (only) the grade level as defined by the Coleman-Liau index (e.g. <code class="language-plaintext highlighter-rouge">"Grade 2"</code> or <code class="language-plaintext highlighter-rouge">"Grade 8" or the like</code>). Be sure to round the resulting index number to the nearest <code class="language-plaintext highlighter-rouge">int</code>!</p>

<details><summary>Hints</summary><ul class="fa-ul">
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>Recall that <code class="language-plaintext highlighter-rouge">round</code> is declared in <code class="language-plaintext highlighter-rouge">math.h</code>, per <a href="https://manual.cs50.io/">manual.cs50.io</a>!</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span>Recall that, when dividing values of type <code class="language-plaintext highlighter-rouge">int</code> in C, the result will also be an <code class="language-plaintext highlighter-rouge">int</code>, with any remainder (i.e., digits after the decimal point) discarded. Put another way, the result will be “truncated.” You might want to cast your one or more values to <code class="language-plaintext highlighter-rouge">float</code> before performing division when calculating <code class="language-plaintext highlighter-rouge">L</code> and <code class="language-plaintext highlighter-rouge">S</code>!</li>
</ul></details>

<p>If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output <code class="language-plaintext highlighter-rouge">"Grade 16+"</code> instead of outputting an exact index number. If the index number is less than 1, your program should output <code class="language-plaintext highlighter-rouge">"Before Grade 1"</code>.</p>

<h2>Walkthrough</h2>

<div class="ratio ratio-16x9" data-video=""><iframe allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen="" class="border" data-video="" src="https://www.youtube.com/embed/AOVyZEh9zgE?modestbranding=0&amp;rel=0&amp;showinfo=0" scrolling="no" id="iFrameResizer0" style="overflow: hidden;"></iframe></div>

<h2>How to Test Your Code</h2>

<p>Try running your program on the following texts, to ensure you see the specified grade level. Be sure to copy only the text, no extra spaces.</p>

<ul class="fa-ul">
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">One fish. Two fish. Red fish. Blue fish.</code> (Before Grade 1)</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">Would you like them here or there? I would not like them here or there. I would not like them anywhere.</code> (Grade 2)</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">Congratulations! Today is your day. You're off to Great Places! You're off and away!</code> (Grade 3)</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.</code> (Grade 5)</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.</code> (Grade 7)</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, "and what is the use of a book," thought Alice "without pictures or conversation?"</code> (Grade 8)</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.</code> (Grade 8)</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy.</code> (Grade 9)</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.</code> (Grade 10)</li>
<li data-marker="*"><span class="fa-li"><i class="fas fa-square"></i></span><code class="language-plaintext highlighter-rouge">A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.</code> (Grade 16+)</li>
</ul>

</body>

![Alt text](image.png)