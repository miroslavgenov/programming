var data = getData("javascript.js").then((data) => console.log(data));

async function getData(url) {
  // if there is no  await there is a probabbility
  // the data is not arived and will retur null
  const res = await fetch(url);
  if (!res.ok) {
    throw new Error(`error ${url} ${res.status}`);
  } else {
    return await res.text();
  }
}
