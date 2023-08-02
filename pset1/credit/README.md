<body class="">

<h1> Credit</h1>
<h2>Credit Cards</h2>

<p>A credit (or debit) card, of course, is a plastic card with which you can pay for goods and services. Printed on that card is a number that’s also stored in a database somewhere, so that when your card is used to buy something, the creditor knows whom to bill. There are a lot of people with credit cards in this world, so those numbers are pretty long: American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers.  And those are decimal numbers (0 through 9), not binary, which means, for instance, that American Express could print as many as 10^15 = 1,000,000,000,000,000 unique cards! (That’s, um, a quadrillion.)</p>

<p>Actually, that’s a bit of an exaggeration, because credit card numbers actually have some structure to them. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow. Of course, a dishonest mathematician could certainly craft a fake number that nonetheless respects the mathematical constraint, so a database lookup is still necessary for more rigorous checks.</p>

<h2>Luhn’s Algorithm</h2>

<p>So what’s the secret formula?  Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:</p>

<ol>
<li>Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.</li>
<li>Add the sum to the sum of the digits that weren’t multiplied by 2.</li>
<li>If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!</li>
</ol>

<p>That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.</p>

<ol>
<li>
<p>For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:</p>

<p><u>4</u>0<u>0</u>3<u>6</u>0<u>0</u>0<u>0</u>0<u>0</u>0<u>0</u>0<u>1</u>4</p>

<p>Okay, let’s multiply each of the underlined digits by 2:</p>

<p>1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2</p>

<p>That gives us:</p>

<p>2 + 0 + 0 + 0 + 0 + 12 + 0 + 8</p>

<p>Now let’s add those products’ digits (i.e., not the products themselves) together:</p>

<p>2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13</p>
</li>
<li>
<p>Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):</p>

<p>13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20</p>
</li>
<li>
<p>Yup, the last digit in that sum (20) is a 0, so David’s card is legit!</p>
</li>
</ol>

<p>So, validating credit card numbers isn’t hard, but it does get a bit tedious by hand. Let’s write a program.</p>

<h2>Implementation Details</h2>

<p>In the file called <code class="language-plaintext highlighter-rouge">credit.c</code> in the <code class="language-plaintext highlighter-rouge">credit</code> directory, write a program that prompts the user for a credit card number and then reports (via <code class="language-plaintext highlighter-rouge">printf</code>) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. So that we can automate some tests of your code, we ask that your program’s last line of output be <code class="language-plaintext highlighter-rouge">AMEX\n</code> or <code class="language-plaintext highlighter-rouge">MASTERCARD\n</code> or <code class="language-plaintext highlighter-rouge">VISA\n</code> or <code class="language-plaintext highlighter-rouge">INVALID\n</code>, nothing more, nothing less. For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card) and that it won’t have leading zeroes. But do not assume that the user’s input will fit in an <code class="language-plaintext highlighter-rouge">int</code>! Best to use <code class="language-plaintext highlighter-rouge">get_long</code> from CS50’s library to get users’ input. (Why?)</p>

<p>Consider the below representative of how your own program should behave when passed a valid credit card number (sans hyphens).</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./credit
Number: 4003600000000014
VISA
</code></pre></div></div>

<p>Now, <code class="language-plaintext highlighter-rouge">get_long</code> itself will reject hyphens (and more) anyway:</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./credit
Number: 4003-6000-0000-0014
Number: foo
Number: 4003600000000014
VISA
</code></pre></div></div>

<p>But it’s up to you to catch inputs that are not credit card numbers (e.g., a phone number), even if numeric:</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./credit
Number: 6176292929
INVALID
</code></pre></div></div>

<p>Test out your program with a whole bunch of inputs, both valid and invalid. (We certainly will!) Here are a <a href="https://developer.paypal.com/api/nvp-soap/payflow/integration-guide/test-transactions/#standard-test-cards">few card numbers</a> that PayPal recommends for testing.</p>

<p>If your program behaves incorrectly on some inputs (or doesn’t compile at all), time to debug!</p>

<h3>Walkthrough</h3>

<div class="ratio ratio-16x9" data-video=""><iframe allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen="" class="border" data-video="" src="https://www.youtube.com/embed/dF7wNjsRBjI?modestbranding=0&amp;rel=0&amp;showinfo=0" scrolling="no" id="iFrameResizer0" style="overflow: hidden;"></iframe></div>






</body>